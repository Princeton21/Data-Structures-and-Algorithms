import java.util.*;

public class BusFullofPassengers {
	
	static Scanner sc = new Scanner(System.in);
	
	public static void solve() {
		int n = sc.nextInt();
		int m = sc.nextInt();
		int q = sc.nextInt();
		HashSet<Integer> hs = new HashSet<>();
		int count = 0;
		boolean found = true;
		sc.nextLine();
		for(int i = 1 ; i <= q ; i++) {
		    String st = sc.nextLine();
		    String ar[] = st.split(" ");
		    char ch = ar[0].charAt(0);
			int num = Integer.valueOf(ar[1]);
			if(count > m) {
				found = false;
				break;
			}
			if(ch == '+') {
				hs.add(num);
				count++;
			}else {
				if(!hs.contains(num)) {
					found = false;
					break;
				}
				count--;
			}
		}
		if(found) {
			System.out.println("Consistent");
		}else {
			System.out.println("Inconsistent");
		}
	}

	public static void main(String[] args) {
		
		int t = sc.nextInt();
		while(t-- > 0) {
			solve();
		}
		sc.close();
	}
}
