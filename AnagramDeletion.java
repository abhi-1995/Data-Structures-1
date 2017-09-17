package myPackage1;
import java.util.*;

public class AnagramDeletion {
	
	public static int numberNeeded(String first, String second){
		String alpha = "abcdefghijklmnopqrstuvwxyz";
		int freq1[] = new int[26];
		int freq2[] = new int[26];
		
		for(int i=0;i<alpha.length();i++){
			for(int j=0;j<first.length();j++){
				if(alpha.charAt(i)==first.charAt(j))
					++freq1[i];
			}
		}
		
		for(int i=0;i<alpha.length();i++){
			for(int j=0;j<second.length();j++){
				if(alpha.charAt(i)==second.charAt(j))
					++freq2[i];
			}
		}
		
		int dels=0;
		for(int i=0;i<26;i++){
			if(freq1[i]!=freq2[i])
				dels+=Math.abs(freq1[i]-freq2[i]);
		}
		return dels;
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		String first = sc.nextLine();
		String second = sc.nextLine();
		
		int num = numberNeeded(first, second);
		System.out.println(num);

	}

}
