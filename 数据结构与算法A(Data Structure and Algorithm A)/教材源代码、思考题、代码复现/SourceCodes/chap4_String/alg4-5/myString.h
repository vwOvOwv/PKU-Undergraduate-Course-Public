#include <string.h> 
#include <assert.h>
using namespace std;
class String { 
private:
      char *str;
      int size;
public:
	String() {
		size = 0 ;  
		str = NULL;
	}
      String(char *s) {
         size = strlen(s) ;  
         str = new char [size +1];
         assert(str != '\0');       // �����ٶ�̬���򲻳ɹ�ʱ�������쳣�˳�
         strcpy(str, s);
      }
      String Substr(int pos,int n ){
           int i;
           int left = size - pos ; 					// ���±�pos���Ҽ�������β�鿴ʣ�೤��
           String tmp;
           char *p, *q;
    // ����7����䣬ȫ��Ϊȡ���Ӵ���׼������
           if (pos >= size) 						// ���±�posֵ��������ʵ�ʴ������򷵻ؿմ�
              return NULL;
           if (n > left ) 						// ��n������pos���ҵ��Ӵ����ȣ����n��С
              n = left;
           delete [] tmp.str; 					// �ͷ�ԭ���Ĵ洢�ռ�
           tmp.str = new char[n+1];
           assert(tmp.str != NULL) ;				// �����ٶ�̬�洢�ռ�ʧ�ܣ����˳�
           p = tmp.str;  						//  pָ���������ݵ��ַ���
           q = &str[pos]; 						//  qָ��ʵ����str�����±�pos��
           for (i =0; i < n; i++)
               *p++ = *q++;  					// ��q��ָ�����ݸ�ֵ�� p����ͬʱ����
           *p = '\0';  						// ѭ����������temp.str�Ľ�βΪ'\0'
           tmp.size = n;
           return tmp;
    }
	friend ostream& operator << (ostream& os, const String& s);  
};

ostream& operator << (ostream& os, const String& s){ 
	os << s.str; 
	return os; 
}; 

