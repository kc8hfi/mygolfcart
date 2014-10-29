
/*
 */

public class GolfCartStatus
{
     public GolfCartStatus()
     {
     }
     public void setIncoming(String s)
     {
          incoming = s;
          System.out.println("GolfCartStatus: " + s);
     }
     private String incoming;
}