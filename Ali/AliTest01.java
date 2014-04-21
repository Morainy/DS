import java.io.*;

public class AliTest01  {
	public static void main(String[] args) throws Exception{
		File f=new File("d:"+File.separator+"Java"+File.separator+"Ali"+File.separator+"t_alibaba_data.csv");
		RandomAccessFile rdf =null;
		rdf=new RandomAccessFile(f,"r");
		String user_id=null;
		String brand_id=null;
		int type=0;
		String str_type=null;
		String visit_datetime=null;
		byte temp[]=new byte[10];
		rdf.skipBytes(38);
		byte ch=0;
		int len =0;
		try{
			//while(true){
				ch =0;
				len=0;
				while ((ch=rdf.readByte())!=',') {
					temp[len]=ch;
					len++;
				}
				user_id=new String(temp,0,len);
				System.out.println("user_id="+user_id);

				ch=0;
				len=0;
				for(int i=0;i<temp.length;i++){
					temp[i]='\0';
				}
				while ((ch=rdf.readByte())!=',') {
					temp[len]=ch;
					len++;
				}
				brand_id=new String(temp,0,len);
				System.out.println("brand_id="+brand_id);

				ch=0;
				len=0;
				for(int i=0;i<temp.length;i++){
					temp[i]='\0';
				}
				while ((ch=rdf.readByte())!=',') {
					temp[len]=ch;
					len++;
				}
				str_type=new String(temp,0,len);
				System.out.println("str_type="+str_type);

				ch=0;
				len=0;
				for(int i=0;i<temp.length;i++){
					temp[i]='\0';
				}
				while ((ch=rdf.readByte())!='\n') {
					temp[len]=ch;
					len++;
				}
				visit_datetime=new String(temp,0,len);
				System.out.println("visit_datetime="+visit_datetime);
			//}
		}
		catch(Exception e){}
		rdf.close();
	}
}