class As_01{
public static int solution(int N, String s) {
    // using a bit mask for comparing values , just like digitalRead() in arduino 
    // A -> 100 0000 000 ->  0x200, 
    // B -> 010 0000 000 ->  0x100, ...
    final int[] BIT_MAP = new int[]{0x200, 0x100, 0x80, 0x40, 0x20, 0x10, 0x8, 0x0, 0x4, 0x2, 0x1};
    // seat matrix bitmap
    // ABC DEFG HJK
    // 100 0000 000
    // 010 0000 000
    // 001 0000 000
    // 000 1000 000
    // 000 0100 000
    // 000 0010 000
    // 000 0001 000
    // 000 0000 100
    // 000 0000 010 
    // 000 0000 001
     int res = 0;
    int[] reserved = new int[N + 1];

    // assume input S is always valid, that is, in format of ${ROW} + ${LABEL}
    String[] seats = s.split(" ");
    for (String seat : seats) {
        if (seat != null && seat.length() > 1) {
            int len = seat.length();
            char label = seat.charAt(len - 1);
            int row = Integer.valueOf(seat.substring(0, len - 1));
            reserved[row] |= BIT_MAP[label - 'A'];
        }
    }
    for (int i = 1; i <= N; i++) {
        if ((reserved[i] & 0x1E0) == 0) {  //using consecutive seat mask E=1110
            reserved[i] |= 0x1E0;
            res++;
        }
        if ((reserved[i] & 0x1E) == 0) {
            reserved[i] |= 0x1E;
            res++;
        }
        if ((reserved[i] & 0x78) == 0) {
            reserved[i] |= 0x78;
            res++;
        }
    }
    return res;
}
public static void main (String args[]){
   
        System.out.println(solution(15, "1B 1D 3C 4F 4E 11H"));
        System.out.println(solution(2, "1A 2F 1C"));
    
}
}