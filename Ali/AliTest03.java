import java.io.*;

public class AliTest03  {
	public static void main(String[] args) throws Exception{
		File f1=new File("d:"+File.separator+"Java"+File.separator+"Ali"+File.separator+"t_alibaba_data.csv");
		File f2=new File("d:"+File.separator+"Java"+File.separator+"Ali"+File.separator+"user_brand_sort.csv");
		File f3=new File("d:"+File.separator+"Java"+File.separator+"Ali"+File.separator+"score_result.txt");
		RandomAccessFile rdf1 =null;
		RandomAccessFile rdf2 =null;
		RandomAccessFile rdf3 =null;
		rdf1=new RandomAccessFile(f1,"r");
		rdf2=new RandomAccessFile(f2,"r");
		rdf3=new RandomAccessFile(f3,"rw");

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

		rdf1.skipBytes(38);


		byte ch=0;
		int len =0;

		int weight=0;
		//enum type{click,buy,save,addCart};

		readRdf2.readFile(rdf2,userArray,brandArray); 
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
				//System.out.println("Integer.parseInt(str_type)="+Integer.parseInt(str_type));

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


				int userIndex=search.binarySearch(userArray,user_id);
				int brandIndex=search.binarySearch(brandArray,brand_id);
				//System.out.println("userIndex="+userIndex);
				//System.out.println("brandIndex="+brandIndex);

				//System.out.println("scoreArray["+userIndex+"]["+brandIndex+"]="+scoreArray[userIndex][brandIndex]);

				switch(Integer.parseInt(str_type)){
					case 0: 
						weight = 1;
						break;
					case 1:
						weight = 5;
						break;
					case 2:
						weight = 3;
						break;
					case 3:
						weight = 2;
						break;
					default:
						break;
				}
				//System.out.println("weight="+weight);
				scoreArray[userIndex][brandIndex]=scoreArray[userIndex][brandIndex]+weight;
				//System.out.println("scoreArray["+userIndex+"]["+brandIndex+"]="+scoreArray[userIndex][brandIndex]);
			}
		}
		catch(Exception e){}
		rdf1.close();
		//System.out.println("row="+row);
		//System.out.println("column="+column);
		//System.out.println("sort_index="+sort_index);
		/*for(int i=0;i<readRdf2.row;i++){
			System.out.print("userArray["+i+"]="+userArray[i]+"\t");
		}*/
		/*for(int i=0;i<readRdf2.column;i++){
			System.out.print("brandArray["+i+"]="+brandArray[i]);
		}*/

		System.out.println("readRdf2.row="+readRdf2.row);
		System.out.println("readRdf2.column="+readRdf2.column);
		for (int i=0;i<readRdf2.row;i++) {
			for(int j=0;j<readRdf2.column;j++){
				//System.out.print("scoreArray["+i+"]["+j+"]="+scoreArray[i][j]+"\t");
				rdf3.writeInt(scoreArray[i][j]);
			}
		}
	}
}

class readRdf2{
	public static int row=0;
	public static int column =0;
	static void readFile(RandomAccessFile rdf,String str1Array[],String str2Array[]) throws Exception{
		String sort_index = null;		
		String user_id_sort = null;
		String brand_id_sort = null; 
		byte temp[]=new byte[10];
		rdf.skipBytes(24);
		try{
			while(true){
				byte ch=0;
				int len=0;
				for(int i=0;i<temp.length;i++){
					temp[i]='\0';
				}
				while((ch=rdf.readByte())!=','){
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
				while((ch=rdf.readByte())!=','){
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
				while((ch=rdf.readByte())!='\n'){
					temp[len]=ch;
					len++;
				}
				brand_id_sort=new String(temp,0,len-1);
				//System.out.println("brand_id_sort="+brand_id_sort);


				if(!user_id_sort.isEmpty()){
					//userArray[row]=Integer.parseInt(user_id_sort);
					str1Array[row]=user_id_sort;
					row++;
				}
				//if(!brand_id_sort.isEmpty()){
					//brandArray[column]=Integer.parseInt(brand_id_sort);
					str2Array[column]=brand_id_sort;
					column++;
				//}
			}
		}
	catch(Exception e){}
	rdf.close();
	}
}

class search{
	public static int binarySearch(String[] srcArray,String des){
	int low=0;
	int high=srcArray.length-1;
	//System.out.println("srcArray.length="+srcArray.length);
	while(low<=high){
		int middle=low+((high-low)>>1);
		//System.out.println("srcArray["+middle+"]="+srcArray[middle]);
		/*if(des.equals(srcArray[middle])){
		return middle;
		}*/
		if(Integer.parseInt(des)==Integer.parseInt(srcArray[middle])){
			return middle;
		}
		/*else if(des.compareTo(srcArray[middle])<0){
			low=middle+1;
		}*/
		else if(Integer.parseInt(des)<Integer.parseInt(srcArray[middle])){
			high=middle-1;
		}
		else{
			low=middle+1;
		}
	}
	return -1;
	}
}