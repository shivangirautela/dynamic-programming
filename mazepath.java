import java.util.ArrayList;
import java.util.*;
public class mazepath
{
    public static Scanner scn = new Scanner(System.in);
public static void main(String [] args)
{
solve();
}
public static ArrayList<String> maze (int si,int ei,int sp,int ep)
{
if(si==sp && ei==ep)
{
    ArrayList<String> base= new ArrayList<> ();
    base.add(" ");
    return base;
}
ArrayList <String> myans= new ArrayList<> ();
if(ei+1<=ep)
{
    ArrayList<String> hrecans=maze(si,ei+1,sp,ep);
    for(String s: hrecans)
    {
        myans.add("H"+s);
    }
}
if(si+1<=sp)
{
    ArrayList<String> vrecans=maze(si+1,ei,sp,ep);
    for(String s: vrecans)
    {
        myans.add("V"+s);
    }
}
        return myans;

}
public static void solve(){
       pathproblems();
   }
   public static void pathproblems(){
    System.out.println(maze(0,3,0,3));
   }
}