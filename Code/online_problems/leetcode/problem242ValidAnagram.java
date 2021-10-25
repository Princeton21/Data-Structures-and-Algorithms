import java.util.Arrays;

public class problem242ValidAnagram {
    public static void main(String[] args) {
        System.out.println(isAnagram("anagram","nagaram"));
    }
    static boolean isAnagram(String s, String t) {
        if(s.length() !=t.length()){
            return false;
        }
        char arrt[]=t.toCharArray();
        char arrs[]=s.toCharArray();
        Arrays.sort(arrt);
        Arrays.sort(arrs);
        for(int i=0;i<arrs.length;i++)
            if(arrs[i]!=arrt[i])
                return false;
        return true;

    }
}
