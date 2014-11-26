
public class cartinfo
{
     public cartinfo()
     {
          fullstring = "";
          status = new String[]{""};
     }
     public cartinfo(String s)
     {
          fullstring = s;
          if (s != null)
          {
               status = s.split(",");
          }
          else
          {
               status = new String[]{""};
          }
     }
     public void setData(String s)
     {
          fullstring = s;
          if (s != null)
               status = s.split(",");
          else
               status = new String[]{""};
     }
     public String getString()
     {
          return fullstring;
     }
     
     private String fullstring;
     
     private String[] status;
     
}//end cartinfo
