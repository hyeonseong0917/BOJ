//public class kakao_2022_1 {
//}
import java.util.HashMap;

class kakao_2022_1 {
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        HashMap<Character, Integer> map=new HashMap<Character, Integer>();
        for(int i=0;i<choices.length;++i){
            int cur_choice=choices[i];
            if(cur_choice<=3){
                //비동의
                char c=survey[i].charAt(0);
                if(map.containsKey(c)){
                    int cur_num=map.get(c);
                    cur_num+=(4-choices[i]);
                    map.put(c,cur_num);
                }else{
                    map.put(c,4-choices[i]);
                }
            }else if(cur_choice>=4){
                //동의
                char c=survey[i].charAt(1);
                if(map.containsKey(c)){
                    int cur_num=map.get(c);
                    cur_num+=(choices[i]-4);
                    map.put(c,cur_num);
                }else{
                    map.put(c,choices[i]-4);
                }
            }
        }
        // return new StringBuilder()
        //     .append(map.getOrDefault('R', 0) >= map.getOrDefault('T', 0) ? 'R' : 'T')
        //     .append(map.getOrDefault('C', 0) >= map.getOrDefault('F', 0) ? 'C' : 'F')
        //     .append(map.getOrDefault('J', 0) >= map.getOrDefault('M', 0) ? 'J' : 'M')
        //     .append(map.getOrDefault('A', 0) >= map.getOrDefault('N', 0) ? 'A' : 'N')
        //     .toString();

//         char first_type,second_type,third_type,fourth_type;
        int[] type_num=new int[] {0,0,0,0,0,0,0,0};
        char[] type_char=new char[] {'R','T','C','F','J','M','A','N'};
        for(int i=0;i<8;++i){
            if(map.containsKey(type_char[i])){
                type_num[i]+=map.get(type_char[i]);
            }
        }
        for(int i=0;i<4;++i){
            if(type_num[i*2]<type_num[i*2+1]){
                answer+=type_char[i*2+1];
            }else{
                answer+=type_char[i*2];
            }
        }
        return answer;
    }
}