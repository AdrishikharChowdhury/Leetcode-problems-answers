import java.util.*;

class Solution {
    class Person implements Comparable<Person> {
        String name;
        int height;
        
        Person(String name, int height) {
            this.name = name;
            this.height = height;
        }
        
        @Override
        public int compareTo(Person other) {
            return other.height - this.height; // for descending order
        }
    }
    
    public String[] sortPeople(String[] names, int[] heights) {
        int n = names.length;
        Person[] people = new Person[n];
        
        for (int i = 0; i < n; i++) {
            people[i] = new Person(names[i], heights[i]);
        }
        
        Arrays.sort(people);
        
        String[] result = new String[n];
        for (int i = 0; i < n; i++) {
            result[i] = people[i].name;
        }
        
        return result;
    }
}