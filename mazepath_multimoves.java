import java.util.ArrayList;
import java.util.*;
public class mazepath_multimoves
{
    public static Scanner scn = new Scanner(System.in);
public static void main(String [] args)
{
solve();
}
public static ArrayList<String> mazepathmulti (int si,int ei,int sp,int ep)
{
if(si==sp && ei==ep)
{
    ArrayList<String> base= new ArrayList<> ();
    base.add(" ");
    return base;
}
ArrayList <String> myans= new ArrayList<> ();
for(int jump=1;ei+jump<=ep;jump++)
{
    ArrayList<String> hrecans=mazepathmulti(si,ei+jump,sp,ep);
    for(String s: hrecans)
    {
        myans.add("H"+jump+s);
    }
}
for(int jump=1;si+jump<=sp;jump++)
{
    ArrayList<String> vrecans=mazepathmulti(si+jump,ei,sp,ep);
    for(String s: vrecans)
    {
        myans.add("V"+jump+s);
    }
}
for(int jump=1;si+jump<=sp && ei+jump<=ep;jump++)
{
    ArrayList<String> vrecans=mazepathmulti(si+jump,ei+jump,sp,ep);
    for(String s: vrecans)
    {
        myans.add("D"+jump+s);
    }
}
        return myans;

}
public static void solve(){
       pathproblems();
   }
   public static void pathproblems(){
    System.out.println(mazepathmulti(0,0,2,2));
   }
}