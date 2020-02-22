#ifndef SMALLVECTOR_H
#define SMALLVECTOR_H

class SmallVector{
	int st_arr[32];
	int *di_arr;
	int st_first_empty = 0, di_first_empty = 0;				//statik ve dinamik array için ilk boþ indexler ve de ayný zamanda eleman sayýlarý
	
	public:
		SmallVector();
		SmallVector(const SmallVector&);
		SmallVector(int arr[], int);
		SmallVector(int);
		//SmallVector(int new_st_arr[], int*, int, int);              //operator tanýmladýgým yerlerde smallvectoru olusturup olusturulmus halini constructora yolladým. o yuzden bu fonksiyonu kullandým zaten olan onstructora dizi yollamak daha mantýklý bunlarý yorum satýrý yapýyorum.
		SmallVector& operator+(const SmallVector&);
		SmallVector& operator*(const int);
		SmallVector& operator=(const SmallVector&);
		const int operator[](int) const;
		int& operator[](int);
		int getSize() const;
		void push_back(int);
		void push_back(int array[], int);
		int pop_back(); 
		SmallVector reverse();
};

SmallVector::SmallVector(){
	
}

SmallVector::SmallVector(const SmallVector& test){
	if(test.di_first_empty == 0){
		for (int i = 0; i < test.st_first_empty; i++){				// eger dinamik kýsmý yoksa sadece statik kopyalýyorum
			st_arr[i] = test.st_arr[i];
		}
	}
	else{
		di_arr = new int[test.di_first_empty];					//dinamik kýsmý varsa yer olusturup orayýda kopyalýyorum
		
		for (int i = 0; i < test.di_first_empty; i++){
			di_arr[i] = test.di_arr[i];
		}
	}
	st_first_empty = test.st_first_empty;
	di_first_empty = test.di_first_empty;
}

SmallVector::SmallVector(int arr[], int size){
	if(size<=32){
		for (int i = 0; i < size; i++){							//32 den kucuk boyutlu olanlar için sadece statige atýyorum
			st_arr[i] = arr[i];
		}
		st_first_empty = size;
	}
	else{
		int a = size-32;					//32 den buyukelr ýcýn statige atýp kalanlarý da dinamige atýyorum yer olusturarak
		
		for (int i = 0; i < 32; i++){
			st_arr[i] = arr[i];
		}
		st_first_empty = 32;
		
		di_arr = new int[a];
		
		for (int i = 0; i < a; i++){
			di_arr[i] = arr[i+32];
		}
		di_first_empty = a;
	}
}

SmallVector& SmallVector::operator+(const SmallVector& z){
	int arr[200];
	int size, i, j;
	
	size = (st_first_empty + z.st_first_empty + di_first_empty + z.di_first_empty);
	
	for(i = 0;i < st_first_empty;i++){				//bir int arrayine herseyi sýra sýra atýp onu sonradan constructora yolluyorum
		arr[i] = st_arr[i];
	}
	if(di_first_empty != 0){
		for(j = 0;j < di_first_empty;i++,j++){
			arr[i] = di_arr[j];
		}
	}
	for(j = 0;j < z.st_first_empty;i++,j++){
		arr[i] = z.st_arr[j];
	}
	if(z.di_first_empty != 0){
		for(j = 0;j < z.di_first_empty;i++,j++){
			arr[i] = z.di_arr[j];
		}
	}
	
	SmallVector sv(arr, size);
	return sv;
}

SmallVector& SmallVector::operator*(const int z){
	int arr[200];
	int size, i, j, k = 0;
	
	size = (st_first_empty + di_first_empty) * z;					//toplamadaki gibi eldekini bir arraye yolluyorum ama bunu çarpýlan sayý kadar tekrarlýyorum
	
	for(i = 0;i < z; i++){
		for(j = 0; j < st_first_empty; j++, k++){
			arr[k] = st_arr[j];
		}
		if(di_first_empty != 0){
			for(j = 0; j < di_first_empty; j++, k++){
				arr[k] = di_arr[j];
			}
		}
	}
	SmallVector sv(arr, size);
	return sv;
}

SmallVector& SmallVector::operator=(const SmallVector& z){	
	int i;

	for(i = 0; i < z.st_first_empty; i++){
		st_arr[i] = z.st_arr[i];
	}																			//direk sagý sola eþitliyorum ehrseyini
	if(z.di_first_empty != 0){
		di_arr = new int[z.di_first_empty];
		for(i = 0; i < z.di_first_empty; i++){
			di_arr[i] = z.di_arr[i];
		}
	}
	st_first_empty = z.st_first_empty;
	di_first_empty = z.di_first_empty;
}

const int SmallVector::operator[](int z) const{ 	//sag taraf
	int size, new_z;
	
	size = st_first_empty + di_first_empty;
	if(z<0){
		new_z = size + z;						//arrayin indexindeki int degeri döndürüyorum
	}										//sayý negatifse de tersten saglayacak sayýya donusturuyorum
	else
		new_z = z;
		
	if(new_z < 32)
		return st_arr[new_z];
	else
		return di_arr[new_z - 32];
}

int& SmallVector::operator[](int z){ 	//sol taraf
	int size, new_z;
	
	size = st_first_empty + di_first_empty;					//yukarýdaki fonksiyonun aynýsý
	if(z<0){
		new_z = size + z;
	}
	else
		new_z = z;
		
	if(new_z < 32)
		return st_arr[new_z];
	else
		return di_arr[new_z - 32];
}

int SmallVector::getSize() const{
	return (st_first_empty + di_first_empty);				//boyutu return ediyorum
}

void SmallVector::push_back(int number){ 
	int arr[200];
	int size, i, j = 0;
	
	size = (st_first_empty + di_first_empty + 1);				//eldekileri bir arraye kopyalayýp yeniden ekliyorum sonuna da gelen sayýyý koyuyorum boylece eger gerekirse dinamigin boyutu artýrýyorum silip yeniden new yaparak
	
	for(i = 0; i < st_first_empty; i++, j++){
		arr[j] = st_arr[i];
	}
	if(di_first_empty != 0){
		for(i = 0; i < di_first_empty; i++, j++){
			arr[j] = di_arr[i];
		}
	}
	arr[size-1] = number;
	
	if(size <= 32){
		for(i = 0;i < 32;i++){
			st_arr[i] = arr[i];
		}
		st_first_empty += 1;
	}
	else{
		delete di_arr;
		di_first_empty += 1;
		st_first_empty = 32;
		di_arr = new int[di_first_empty];
		for(i = 0;i < 32;i++){
			st_arr[i] = arr[i];
		}
		for(j = 0; i < size; j++, i++){
			di_arr[j] = arr[i];
		}
	}
}

void SmallVector::push_back(int array[], int size_array){
	int arr[200];
	int size, i, j = 0;
	
	size = (st_first_empty + di_first_empty + size_array);				//yukarýdakinin aynýsýnýn arraylisi
	
	for(i = 0; i < st_first_empty; i++, j++){
		arr[j] = st_arr[i];
	}
	if(di_first_empty != 0){
		for(i = 0; i < di_first_empty; i++, j++){
			arr[j] = di_arr[i];
		}
	}	
	for(i = 0; i < size_array; i++, j++){
		arr[j] = array[i];
	}
	
	if(size <= 32){
		for(i = 0;i < 32;i++){
			st_arr[i] = arr[i];
		}
		st_first_empty += size_array;
	}
	else{
		delete di_arr;
		di_first_empty += (size_array + st_first_empty - 32);
		st_first_empty = 32;
		di_arr = new int[di_first_empty];
		for(i = 0;i < 32;i++){
			st_arr[i] = arr[i];
		}
		for(j = 0; i < size; j++, i++){
			di_arr[j] = arr[i];
		}
	}
}

int SmallVector::pop_back(){					
	int temp;
	int temp_arr[200];
	int i;
	
	if(di_first_empty != 0){
		di_first_empty--;
		temp = di_arr[di_first_empty];					//eger dinamik kýsýmda eleman varsa 1 eksigine kdar yedekleyip silip 1 eksik yer ayýrýp geri dolduruyorum
		for(i = 0;i < di_first_empty;i++){
			temp_arr[i] = di_arr[i];
		}
		delete di_arr;
		if(di_first_empty != 0){
			di_arr = new int[di_first_empty];
			for(i = 0;i<di_first_empty;i++){
				di_arr[i] = temp_arr[i];
			}
		}
		return temp;
	}
	else{
		st_first_empty--;
		temp = st_arr[st_first_empty];
		st_arr[st_first_empty] = 0;
		return temp;
	}
}

SmallVector SmallVector::reverse(){			//bir adet arrayin içine herseyi tersten dolduruyorum ve bu arrayi constructora yolluyorum
	int arr[200];
	int size, i = 0, j;
	
	size = st_first_empty + di_first_empty;
	
	if(di_first_empty != 0){
		for(i = 0, j = di_first_empty-1;j >= 0;i++, j--){
			arr[i] = di_arr[j];
		}
	}
	for(j = st_first_empty-1; j >= 0;i++,j--){
		arr[i] = st_arr[j];
	}
	
	SmallVector sv(arr, size);
	return sv;
}

//buradan asagýsý fazlalýk kod basta yaptýgým bir hatadan dolayý ama silmedim





/*SmallVector::SmallVector(int new_st_arr[], int *new_di_arr, int new_st_first_empty, int new_di_first_empty){
	st_first_empty = new_st_first_empty;
	di_first_empty = new_di_first_empty;
	for (int i = 0; i < st_first_empty; i++){
		st_arr[i] = new_st_arr[i];
	}
	if(di_first_empty != 0){
		di_arr = new int[di_first_empty];
		for (int i = 0; i < di_first_empty; i++){
			di_arr[i] = new_di_arr[i];
		}
	}
	
	delete[] new_st_arr;
	delete new_di_arr;
}*/

/*SmallVector& SmallVector::operator+(const SmallVector& z){
	int new_st_arr[32];
	int *new_di_arr;
	int new_st_first_empty = 0, new_di_first_empty = 0;
	int i, j;
	
	if((st_first_empty + z.st_first_empty + di_first_empty + z.di_first_empty) <= 32){
		for (i = 0; i < st_first_empty; i++){
			new_st_arr[i] = st_arr[i];
		}
		for (j = 0; j < z.st_first_empty; i++, j++){
			new_st_arr[i] = z.st_arr[j];
		}
		new_st_first_empty = i;
	}
	else{
		new_st_first_empty = 32;
		new_di_arr = new int[(st_first_empty + z.st_first_empty + di_first_empty + z.di_first_empty - 32)];
		
		for (i = 0; i < st_first_empty; i++){
			new_st_arr[i] = st_arr[i];
		}
		if(i == 32){
			if(di_first_empty != 0){
				for (i = 0, j = 0; j < di_first_empty; i++, j++){
					new_di_arr[i] = di_arr[j];
				}
			}
			for (j = 0; j < z.st_first_empty; i++, j++){
				new_di_arr[i] = z.st_arr[j];
			}
			if(z.di_first_empty != 0){
				for (j = 0; j < z.di_first_empty; i++, j++){
					new_di_arr[i] = z.di_arr[j];
				}
			}
			new_di_first_empty = i;
		}
		else{
			for (j = 0; j < z.st_first_empty; i++, j++){
				if(i == 32)
					break;
				new_st_arr[i] = z.st_arr[j];
			}
			for (i = 0; j < z.st_first_empty; i++, j++){
				new_di_arr[i] = z.st_arr[j];
			}
			if(z.di_first_empty != 0){
				for (j = 0; j < z.di_first_empty; i++, j++){
					new_di_arr[i] = z.di_arr[j];
				}
			}
			new_di_first_empty = i;
		}		
	}
	return SmallVector(new_st_arr, new_di_arr, new_st_first_empty, new_di_first_empty);
}*/

/*SmallVector& SmallVector::reverse(){
	int new_st_arr[32];
	int *new_di_arr;
	int new_st_first_empty = st_first_empty, new_di_first_empty = di_first_empty;
	int i, j;
	
	if(di_first_empty == 0){
		for (i = st_first_empty-1, j=0; i >= 0; i--, j++){
			new_st_arr[j] = st_arr[i];
		}
	}
	else{
		if(di_first_empty <= 32){
			for (i = di_first_empty-1, j = 0; i >= 0; i--, j++){
				new_st_arr[j] = di_arr[i];
			}
			for (i = st_first_empty-1; j<32; i--, j++){
				new_st_arr[j] = st_arr[i];
			}
			for (j = 0; i >= 0; i--, j++){
				new_di_arr[j] = st_arr[i];
			}
		}
		else{
			for (i = di_first_empty-1; j<32; i--, j++){
				new_st_arr[j] = di_arr[i];
			}
			for (j = 0; i >= 0; i--, j++){
				new_di_arr[j] = di_arr[i];
			}
			for (i = st_first_empty-1; i >= 0; i--, j++){
				new_st_arr[j] = st_arr[i];
			}
		}
	}
}*/

#endif
