
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
          //System.out.println("GolfCartStatus: " + s);
     }
     
     public String getStatus()
     {
          return incoming;
     }
     
     private String incoming;
}
