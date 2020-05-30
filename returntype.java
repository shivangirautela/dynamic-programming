import java.util.*;
public class returntype{
    public static Scanner scn = new Scanner(System.in);
    public static void main(String [] args)
    {
        solve();
    }
    public static void solve()
    {
        //basicques();
        permutationq();
        
    }
    // basic =========================================================================================
    public static void basicques()
    {
        System.out.println(subsequence("1234"));
    }
    public static ArrayList<String> subsequence(String str)
    {
        if(str.length()==0)
        {
            ArrayList <String> base=new  ArrayList<> ();
            base.add(str);
            return base;
        }
        char ch= str.charAt(0);
        String reststr=str.substring(1);

        ArrayList <String> recans= subsequence(reststr);
        ArrayList <String> myans=new ArrayList<> ();

        for(String s: recans)
        {
            myans.add(s);
            myans.add(s+ch);
        }
        return myans;
    } 
    public static void permutationq()
    {
        System.out.println(subseq("abc"));
    }
    public static ArrayList<String> subseq (String str)
    {
        if(str.length()==0)
        {
            ArrayList <String> base=new  ArrayList<> ();
            base.add("");
            return base;
        }
        char ch= str.charAt(0);
        String reststr=str.substring(1);


        ArrayList <String> recans= subseq(reststr);
        ArrayList <String> myans=new ArrayList<> ();

        for(String s: recans)
        {
            for(int i=0;i<=s.length();i++)       //for unoque
            {
                String one=s.substring(0,i);
                String two=s.substring(i);
                String ans= one+ch+two;
                myans.add(ans);
            }
        }
        return myans;
    }
}

