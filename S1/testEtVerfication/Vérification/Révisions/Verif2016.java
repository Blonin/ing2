//@+ CheckArithOverflow = no
public class Verif2016 {

  /*@ requires 
    @   t1 != null && t2 != null && t1.length >= t2.length >= 1;
    @ ensures 
    @   \result <==> \exists integer i; 0 <= i < t1.length - t2.length + 1 && \forall integer j; 0 <= j < t2.length ==> t1[i+j] == t2[j];
    @*/
  public boolean subSeq(int[] t1, int[] t2) {
    int i = 0;
    /*@ loop_invariant
      @  0 <= i <= t1.length - t2.length + 1 && 
      @  \forall integer x; 0 <= x < i ==> (\exists integer y; 0 <= y < t2.length && t1[x+y] != t2[y]);
      @ loop_variant t1.length - i; 
      @*/
    while (i < t1.length - t2.length + 1) {
      int j = 0;
      /*@ loop_invariant
		@   0 <= i < t1.length - t2.length + 1 && 
        @   0 <= j <= t2.length && 
        @   \forall integer k; 0 <= k < j ==> t1[i+k] == t2[k];
        @ loop_variant t2.length - j; 
        @*/
      while (j < t2.length && t1[i+j] == t2[j]) {
        j = j + 1;
      }
      if (j == t2.length)
        return true;
      i = i + 1;
    }
    return false;
  }

}
