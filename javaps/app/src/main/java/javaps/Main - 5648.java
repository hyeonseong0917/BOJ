/*
 * Click `Run` to execute the snippet below!
 */

import java.io.*;
import java.util.*;

/*
 * To execute Java, please define "static void main" on a class
 * named Solution.
 *
 * If you need more classes, simply define them inline.
 */

class Solution {
  // 
  static Scanner sc=new Scanner(System.in);
  static int n;
  static ArrayList<String> v=new ArrayList<>();
  static void Input(){
    n=sc.nextInt();
    for(int i=0;i<n;++i){
      String s=sc.next();
      v.add(s);
    }

  }
  static String GetNum(String s){
    String t="";
    ArrayList<Character> vt=new ArrayList<>();
    for(int i=0;i<s.length();++i){
      vt.add(s.charAt(i));
    }
    Collections.reverse(vt);
    for(int i=0;i<vt.size();++i){
      t+=vt.get(i);
    }
    int idx=0;
    for(int i=0;i<vt.size();++i){
      if(t.charAt(i)!='0'){
        idx=i;
        break;
      }
    }
    String ans="";
    int k=vt.size();
    ans=t.substring(idx,k);
    return ans;
  }
  static class StrLen implements Comparable<StrLen>{
    String cur_str;
    int cur_len;
    public StrLen(String cur_str, int cur_len){
      this.cur_str=cur_str;
      this.cur_len=cur_len;
    }
    @Override
    public int compareTo(StrLen other){
      if(this.cur_len==other.cur_len){
        return this.cur_str.compareTo(other.cur_str);
      }
      return this.cur_len-other.cur_len;
    }
  }
  static void Solve(){
    ArrayList<StrLen> arr=new ArrayList<>();
    for(int i=0;i<v.size();++i){
      String s=v.get(i);
      String cur_num=GetNum(s);
      int cs=cur_num.length();
      arr.add(new StrLen(cur_num,cs));
    }
    Collections.sort(arr);
    for(int i=0;i<arr.size();++i){
      System.out.println(arr.get(i).cur_str);
    }
  }
  public static void main(String[] args) {
      Input();
      Solve();
  }
}
