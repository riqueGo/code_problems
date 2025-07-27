package design_in_memory_file_system;

import java.util.*;

class FileNode {
    boolean isFile = false;
    StringBuilder content = new StringBuilder();
    Map<String, FileNode> children = new HashMap<>();
}

class FileSystem {
    private final FileNode root;

    public FileSystem() {
        root = new FileNode();
    }

    private FileNode getFileNode(String path) {
        FileNode curr = root;
        if ("/".equals(path)) return curr;
        String[] parts = path.split("/");
        for (String part : parts) {
            if (part.isEmpty()) continue;
            curr = curr.children.get(part);
        }
        return curr;
    }

    private FileNode putFileNode(String path) {
        FileNode curr = root;
        String[] parts = path.split("/");
        for (String part : parts) {
            if (part.isEmpty()) continue;
            curr.children.putIfAbsent(part, new FileNode());
            curr = curr.children.get(part);
        }
        return curr;
    }

    public List<String> ls(String path) {
        FileNode node = getFileNode(path);
        if (node.isFile) {
            String[] parts = path.split("/");
            return Arrays.asList(parts[parts.length - 1]);
        }
        List<String> res = new ArrayList<>(node.children.keySet());
        Collections.sort(res);
        return res;
    }

    public void mkdir(String path) {
        putFileNode(path);
    }

    public void addContentToFile(String filePath, String content) {
        FileNode node = putFileNode(filePath);
        node.isFile = true;
        node.content.append(content);
    }

    public String readContentFromFile(String filePath) {
        return getFileNode(filePath).content.toString();
    }
}