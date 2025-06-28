package course_schedule;

import java.util.ArrayList;

class Solution {
    private ArrayList<Integer>[] dependenciesByCourses = new ArrayList[2000];
    private int[] visited = new int[2000];
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        for(int[] courses : prerequisites) {
            if(dependenciesByCourses[courses[1]] == null) {
                dependenciesByCourses[courses[1]] = new ArrayList<>();
            }
            dependenciesByCourses[courses[1]].add(courses[0]);
        }

        for(int i = 0; i < 2000; i++) {
            if(!dfs(i)) return false;
        }
        return true;
    }

    private boolean dfs(int currCourse) {
        if(visited[currCourse] == 1) return false;
        else if(visited[currCourse] == 2 || dependenciesByCourses[currCourse] == null) return true;

        visited[currCourse] = 1;

        for(Integer dependentCourse : dependenciesByCourses[currCourse]) {
            if(!dfs(dependentCourse)) return false;
        }

        visited[currCourse] = 2;
        return true;
    }
}
