import java.io.*;
import java.lang.Math.*;

public class AliTest05  {
	public static void main(String[] args) throws Exception{
		File f1=new File("d:"+File.separator+"Java"+File.separator+"Ali"+File.separator+"t_alibaba_data.csv");
		File f2=new File("d:"+File.separator+"Java"+File.separator+"Ali"+File.separator+"user_brand_sort.csv");
		File f3=new File("d:"+File.separator+"Java"+File.separator+"Ali"+File.separator+"score_result.txt");
		File f4=new File("d:"+File.separator+"Java"+File.separator+"Ali"+File.separator+"user_similarity.txt");
		File f5=new File("d:"+File.separator+"Java"+File.separator+"Ali"+File.separator+"result.txt");
		RandomAccessFile rdf1 =null;
		RandomAccessFile rdf2 =null;
		RandomAccessFile rdf3 =null;
		RandomAccessFile rdf4 =null;
		RandomAccessFile rdf5 =null;
		rdf1=new RandomAccessFile(f1,"r");  //源文件，t_alibaba_data.csv
		rdf2=new RandomAccessFile(f2,"r");  //排序后的数据，user_brand_sort.csv
		rdf3=new RandomAccessFile(f3,"rw");  //打分结果的值，调试中检测用
		rdf4=new RandomAccessFile(f4,"rw");  //  用户相似性的值，调试用
		rdf5=new RandomAccessFile(f5,"rw");  //  最终的推荐结果

		String user_id=null;    //源文件中的用户ID
		String brand_id=null;   //源文件中的品牌ID
		int type=0;              
		String str_type=null;    //源文件的行为类型，0表示点击，1表示购买，2表示收藏，3表示加入购物车
		String visit_datetime=null;   //访问时间
		byte temp[]=new byte[10];
		int [][] scoreArray = new int [884][9531];   //打分矩阵
		float [][] userSim = new float [884][884];   //用户相似性矩阵
		float [][] preScoreArray = new float [884][9531];   //预测的打分矩阵

		int row = 0 ;   
		int column = 0 ;

		String [] userArray = new String [884];    //排序后的用户数组，映射文件
		String [] brandArray = new String [9531];   //排序后的品牌数组，映射文件

		rdf1.skipBytes(38);     //读取源文件时跳过文件前面对字段的说明文字


		byte ch=0;   
		int len =0;

		int weight=0;
		//enum type{click,buy,save,addCart};

		readRdf2.readFile(rdf2,userArray,brandArray);  //将排序后的文件读入用户数组和品牌数组中
		try{
			while(true){           //对源文件的读取
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
						weight = 1;    //点击时权重为1
						break;
					case 1:
						weight = 5;    //购买时权重为5
						break;
					case 2:
						weight = 3;    //收藏时权重为3
						break;
					case 3:
						weight = 2;    //加入购物车时权重为2
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
		/*for (int i=0;i<readRdf2.row;i++) {
			for(int j=0;j<readRdf2.column;j++){
				//System.out.print("scoreArray["+i+"]["+j+"]="+scoreArray[i][j]+"\t");
				rdf3.writeInt(scoreArray[i][j]);
			}
		}*/
		/*for(int i=0;i<userSim[0].length;i++){
			System.out.print("userSim[0]["+i+"]="+userSim[0][i]);
		}*/

		user_similarity.userSimilarity(scoreArray,userSim);
		System.out.println("userSim[0][875]="+userSim[0][875]);
		System.out.println("userSim[875][0]="+userSim[875][0]);
		/*for(int i=0;i<userSim[0].length;i++){
			System.out.print("userSim[0]["+i+"]="+userSim[0][i]);
		}*/
		/*for (int i=0;i<userSim.length;i++) {
			for(int j=0;j<userSim[0].length;j++){
				rdf4.writeFloat(scoreArray[i][j]);
			}
		}*/


		pre_score.preScore(userSim,scoreArray,preScoreArray);
		/*for(int i=0;i<preScoreArray[1].length;i++){
			System.out.print("preScoreArray[1]["+i+"]="+preScoreArray[1][i]+"\t");
		}*/

		final int k=50;
		int [][] resultIndex = new int [readRdf2.row][k];
		for(int i=0;i<readRdf2.row;i++){
			for(int j=0;j<k;j++){
				resultIndex[i][j]=-1;
			}
		}
		for(int i=0;i<readRdf2.row;i++){
			top_k.topK(preScoreArray[i],resultIndex[i]);
		}

		/*for(int i=0;i<readRdf2.row;i++){
			for(int j=0;j<k;j++){
				System.out.print("preScoreArray["+i+"]["+resultIndex[i][j]+"]="+preScoreArray[i][resultIndex[i][j]]+"\t");
			}
		}*/

		/*for(int i=0;i<readRdf2.row;i++){
			if(resultIndex[i][0]>0){
				rdf5.writeBytes(userArray[i]+"\t");
				for(int j=0;j<k;j++){
					if(resultIndex[i][j]>0){
						rdf5.writeBytes(brandArray[resultIndex[i][j]]+",");
					}
				}
				//rdf5.writeBytes(brandArray[resultIndex[i][k-1]]+"\n");
				rdf5.writeBytes("\n");
			}
		}*/
		/*for (int i=0;i<readRdf2.row ; i++) {
			System.out.print("top_k.countArray["+i+"]="+top_k.countArray[i]+"\t");
		}*/
		for(int i=0;i<readRdf2.row;i++){
			if(top_k.countArray[i]>0){
				rdf5.writeBytes(userArray[i]+"\t");
				for(int j=0;j<(top_k.countArray[i])-1;j++){
					if(resultIndex[i][j]>0){
						rdf5.writeBytes(brandArray[resultIndex[i][j]]+",");
					}
				}
				rdf5.writeBytes(brandArray[resultIndex[i][(top_k.countArray[i])-1]]+"\n");
			}
		}
	rdf1.close();
	rdf2.close();
	rdf3.close();
	rdf4.close();
	rdf5.close();
	}
}

class readRdf2{

	//实现读文件
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
	}
}

class search{
	//实现二分查找
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

class user_similarity{

	//利用余弦相似性计算用户相似性，
	public static void userSimilarity(int [][] arrayInput,float [][] arrayoutput){
		int dot_product=0;
		float mod1=0.0f;
		float mod2=0.0f;
		float sum1=0.0f;
		float sum2=0.0f;
		float similarity=0.0f;
		//System.out.println("arrayInput.length="+arrayInput.length);
		//System.out.println("arrayInput[0].length="+arrayInput[0].length);
		//System.out.println("arrayoutput.length="+arrayoutput.length);
		//System.out.println("arrayoutput[0].length="+arrayoutput[0].length);
		for(int i=0;i<arrayInput.length;i++){
			for(int j=0;j<arrayInput.length;j++){
				dot_product=0;
				sum1=0.0f;
				sum2=0.0f;
				for(int k=0;k<arrayInput[0].length;k++){
					dot_product=dot_product+arrayInput[i][k]*arrayInput[j][k];
					//sum2=sum2+(float)Math.pow(arrayInput[j][k],2);
					//sum1=sum1+(float)Math.pow(arrayInput[i][k],2);
					sum2=sum2+arrayInput[j][k]*arrayInput[j][k];
					sum1=sum1+arrayInput[i][k]*arrayInput[i][k];
				}
				mod2=(float)Math.sqrt(sum2);
				mod1=(float)Math.sqrt(sum1);
				similarity=dot_product/(mod1*mod2);
				arrayoutput[i][j]=similarity;
			}
		}
	}
}

class pre_score{

	// 计算预测得分，也就是实现两矩阵相乘
	public static void preScore(float [][] inputArray1,int [][] inputArray2,float [][] outputArray){
		float sum=0.0f;
		for(int i=0;i<inputArray1.length;i++){
			for(int j=0;j<inputArray2[0].length;j++){
				sum=0.0f;
				for(int k=0;k<inputArray2.length;k++){
					sum+=inputArray1[i][k]*inputArray2[k][j];
				}
				outputArray[i][j]=sum;
			}
		}
	}
}

/*class top_k{
	topK的第一个版本outputArray中存储inputArray中前 K个得分较高的元素值的索引

	public static void topK(float [] inputArray,int [] outputArray){
		float min=1000f;
		int t=0;
		for(int i=0;i<inputArray.length;i++){
			min=1000f;   //尽量将min设为一个较大的值
			for(int j=0;j<outputArray.length;j++){
				int index = outputArray[j];
				if(inputArray[index]<min){
					min=inputArray[index];
					t=j;
				}
			}  // 循环找出outputArray中最小的值将其赋值给min
			if(inputArray[i]>min){
				outputArray[t]=i;
			}
		}
	}
}*/
class top_k{
	/*
		topk的第二个版本，用outputArray存储inputArray中大于阈值的索引值。
		countArray中存储的是outputArray中真实的元素个数
	*/
	public static int [] countArray = new int [readRdf2.row];
	public static int t = 0;
	public static void topK(float [] inputArray,int [] outputArray){
		final float threshold = 67f;
		int count = 0;
		for(int i=0;i<inputArray.length;i++){
			if(inputArray[i]>threshold && count<outputArray.length){
				outputArray[count]=i;
				count++;
			}
		}
		countArray[t]=count;
		t++;
	}
}