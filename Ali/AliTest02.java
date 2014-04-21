import java.io.*;

public class AliTest02  {
	public static void main(String[] args) throws Exception{
		File f1=new File("d:"+File.separator+"Java"+File.separator+"Ali"+File.separator+"t_alibaba_data.csv");
		File f2=new File("d:"+File.separator+"Java"+File.separator+"Ali"+File.separator+"user_brand_sort.csv");
		RandomAccessFile rdf1 =null;
		RandomAccessFile rdf2 =null;
		rdf1=new RandomAccessFile(f1,"r");
		rdf2=new RandomAccessFile(f2,"r");

		String user_id=null;
		String brand_id=null;
		int type=0;
		String str_type=null;
		String visit_datetime=null;
		byte temp[]=new byte[10];
		final int[][] scoreArray = new int [884][9531];
		int row = 0 ;
		int column = 0 ;

		String [] userArray = new String [884];
		String [] brandArray = new String [9531];
		String sort_index = null;
		String user_id_sort = null;
		String brand_id_sort = null;

		rdf1.skipBytes(38);
		rdf2.skipBytes(24);

		byte ch=0;
		int len =0;
		try{
			while(true){
				ch =0;
				len=0;
				while ((ch=rdf1.readByte())!=',') {
					temp[len]=ch;
					len++;
				}
				user_id=new String(temp,0,len);
				//System.out.println("user_id="+user_id);

				ch=0;
				len=0;
				for(int i=0;i<temp.length;i++){
					temp[i]='\0';
				}
				while ((ch=rdf1.readByte())!=',') {
					temp[len]=ch;
					len++;
				}
				brand_id=new String(temp,0,len);
				//System.out.println("brand_id="+brand_id);

				ch=0;
				len=0;
				for(int i=0;i<temp.length;i++){
					temp[i]='\0';
				}
				while ((ch=rdf1.readByte())!=',') {
					temp[len]=ch;
					len++;
				}
				str_type=new String(temp,0,len);
				//System.out.println("str_type="+str_type);

				ch=0;
				len=0;
				for(int i=0;i<temp.length;i++){
					temp[i]='\0';
				}
				while ((ch=rdf1.readByte())!='\n') {
					temp[len]=ch;
					len++;
				}
				visit_datetime=new String(temp,0,len);
				//System.out.println("visit_datetime="+visit_datetime);

				ch=0;
				len=0;
				for(int i=0;i<temp.length;i++){
					temp[i]='\0';
				}
				while((ch=rdf2.readByte())!=','){
					temp[len]=ch;
					len++;
				}
				sort_index=new String(temp,0,len); 
				//System.out.println("sort_index="+sort_index);


				ch=0;
				len=0;
				for(int i=0;i<temp.length;i++){
					temp[i]='\0';
				}
				while((ch=rdf2.readByte())!=','){
					temp[len]=ch;
					len++;
				}
				user_id_sort=new String(temp,0,len);
				//System.out.println("user_id_sort="+user_id_sort);



				ch=0;
				len=0;
				for(int i=0;i<temp.length;i++){
					temp[i]='\0';
				}
				while((ch=rdf2.readByte())!='\n'){
					temp[len]=ch;
					len++;
				}
				brand_id_sort=new String(temp,0,len);
				//System.out.println("brand_id_sort="+brand_id_sort);


				if(!user_id_sort.isEmpty()){
					//userArray[row]=Integer.parseInt(user_id_sort);
					userArray[row]=user_id_sort;
					row++;
				}
				if(!brand_id_sort.isEmpty()){
					//brandArray[column]=Integer.parseInt(brand_id_sort);
					brandArray[column]=brand_id_sort;
					column++;
				}
			}
		}
		catch(Exception e){}
		rdf1.close();
		rdf2.close();
		System.out.println("row="+row);
		System.out.println("column="+column);
		System.out.println("sort_index="+sort_index);
		/*for(int i=0;i<row;i++){
			System.out.print("userArray["+i+"]="+userArray[i]+"\t");
		}*/
		for(int i=0;i<column;i++){
			System.out.print("brandArray["+i+"]="+brandArray[i]+"\t");
		}
	}
}
