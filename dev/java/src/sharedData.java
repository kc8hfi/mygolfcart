public class sharedData 
{
	private String readFromArd;
	private String readFromNet;
	private boolean aliveNet = true;
	private boolean aliveArd = true;

	public sharedData()
	{
		readFromArd = "";
		readFromNet = "";
	}
	
	public void setReadArd(String temp)
	{
		readFromArd = temp;
	}
	
	public void setReadNet(String temp)
	{
		readFromNet = temp;
	}
	
	public String getReadArd()
	{
		return readFromArd;
	}
	
	public String getReadNet()
	{
		return readFromNet;
	}
	
	public void setAliveArd(boolean temp)
	{
		aliveArd = temp;
	}
	
	public void setAliveNet(boolean temp)
	{
		aliveNet = temp;
	}
	
	public boolean getAlive()
	{
		if(aliveNet&&aliveArd)
			return true;
		else 
			return false;
	}
}
