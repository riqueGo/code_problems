package accounts_merge;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class DisjoinSet {
    List<Integer> parent = new ArrayList<>();
    List<Integer> size = new ArrayList<>();

    public DisjoinSet(int n) {
        for(int i = 0; i < n; i++) {
            parent.add(i);
            size.add(1);
        }
    }

    public int findUnionParent(int node) {
        if(node == parent.get(node)) return node;

        int unionParent = findUnionParent(parent.get(node));
        parent.set(node, unionParent);
        return parent.get(node); 
    }

    public void unionBySize(int u, int v) {
        int unionParentU = findUnionParent(u);
        int unionParentV = findUnionParent(v);

        if(unionParentU == unionParentV) return;

        int newSize = size.get(unionParentU) + size.get(unionParentV);
        if(size.get(unionParentV) < size.get(unionParentU)) {
            parent.set(unionParentV, unionParentU);
            size.set(unionParentU, newSize);
        } else {
            parent.set(unionParentU, unionParentV);
            size.set(unionParentV, newSize);
        }
    }

}

class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        int n = accounts.size();
        DisjoinSet ds = new DisjoinSet(n);
        HashMap<String, Integer> accountIndexByEmail = new HashMap<>();

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts.get(i).size(); j++) {
                String email = accounts.get(i).get(j);
                if(accountIndexByEmail.containsKey(email)) {
                    ds.unionBySize(i, accountIndexByEmail.get(email));
                } else {
                    accountIndexByEmail.put(email, i);
                }
            }
        }

        ArrayList<String>[] mergeEmail = new ArrayList[n];
        for(int i = 0; i < n; i++) {
            mergeEmail[i] = new ArrayList<String>();
        }

        for(Map.Entry<String, Integer> it : accountIndexByEmail.entrySet()) {
            String email = it.getKey();
            int node = ds.findUnionParent(it.getValue());
            mergeEmail[node].add(email);
        }

        List<List<String>> ans = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            if(mergeEmail[i].size() == 0) continue;

            Collections.sort(mergeEmail[i]);

            List<String> tmp = new ArrayList<>();
            tmp.add(accounts.get(i).get(0));
            for(String email : mergeEmail[i]) {
                tmp.add(email);
            }
            ans.add(tmp);
        }

        return ans;
    }
}
