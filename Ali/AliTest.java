import java.io.*;

public class AliTest {
	public static void main(String[] args) throws Exception{
		DataInputStream dis =null;
		File f=new File("d:"+File.separator+"Java"+File.separator+"Ali"+File.separator+"t_alibaba_data.csv");
		dis = new DataInputStream(new FileInputStream(f));
		char temp[]=null;
		int len=0;
		String user_id=null;
		String brand_id=null;
		int  type=0;
		String visit_datetime=null;
		char c=0;
		try{
			temp=new char[200];
			while((c=dis.readChar())!=',' && c!='\n'){
				System.out.print("c="+c+"\t");
				temp[len]=c;
				len++;
			}
			user_id=new String(temp,0,len);
			dis.readChar();


			len=0;
			while((c=dis.readChar())!=','){
				temp[len]=c;
				len++;
			}
			brand_id=new String(temp,0,len);
			dis.readChar();
			System.out.println("user_id="+user_id+"brand_id="+brand_id);
		}
		catch(IOException e){
			e.printStackTrace();
		}

	}
}