

const int StackSize=100;  //100ֻ��ʾ�����ݣ�����ݾ������ⶨ��
template <class T>
class BothStack 
{
public:
    BothStack( ) {top1= -1;  top2=StackSize;}  //���캯����������ջ�ֱ��ʼ��
    ~BothStack( ) { }      //��������
    void Push(int i, T x);   //��Ԫ��xѹ��ջi
    T Pop(int i);          //��ջiִ�г�ջ����
    T GetTop(int i);       //ȡջi��ջ��Ԫ��
    bool Empty(int i);     //�ж�ջi�Ƿ�Ϊ��ջ
private:
    T data[StackSize];     //�������ջ������
    int top1, top2;        //����ջ��ջ��ָ�룬�ֱ�ָ����Ե�ջ��Ԫ���������е��±�
};

#endif