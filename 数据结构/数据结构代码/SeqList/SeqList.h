//SeqList.h ������SeqList,�ļ���ΪSeqList.h
#ifndef SeqList_H
#define SeqList_H
const int MaxSize=100;  //100ֻ��ʾ���Ե����ݣ����Ը���ʵ��������嶨��
template <class T>      //����ģ����SeqList
class SeqList
{
public:
   SeqList( );       //�޲ι��캯��
   SeqList(T a[], int n);       //�вι��캯��
   ~SeqList();             //��������Ϊ��
   int Length();           //�����Ա�ĳ���
   T Get(int i);         //��λ���ң�ȡ���Ա�ĵ�i��Ԫ��
   int Locate(T x);       //��ֵ���ң������Ա���ֵΪx��Ԫ�����
   void Insert(int i, T x);  //�����Ա��е�i��λ�ò���ֵΪx��Ԫ��
   T Delete(int i);        //ɾ�����Ա�ĵ�i��Ԫ��
   void PrintList();       //�������Ա���������������Ԫ��
private:
   T data[MaxSize];      //�������Ԫ�ص�����
   int length;            //���Ա�ĳ���
};
#endif