#pragma once
#define MAX_LEN 100000	//�������������
#define DEFAULT_INITIAL_VOLUMN 100	//Ĭ�ϳ�ʼ����������

//���µ�class TӦ���߱���С��ϵ�ġ��ɱȽϵ�
template <class T>
struct Node {
	T data;
	Node *previous;		//ָ��ǰһ�����
	Node *next;			//ָ���һ�����
};

template <class T>
class Priority_Linklist {
private:
	Node empty_list_h;			//������ͷ����ͷ��������������������ݼ�¼��ע��������ָ�롣
	Node full_list_h;			//������ͷ����ͷ��������������������ݼ�¼��ע��������ָ�롣
	int m_size;
	int m_volumn;

	int increment();			//��������push()��Ҫʹ�õķ���
								//������������Ϊ�գ��ȼ��m_volumn * 2�Ƿ����MAX_LEN��������ڣ������ݷǷ�������-1
								//����������ݣ�����m_volumn��������Node��Ȼ�����m_volumn����������0.
public:
	Priority_Linklist(int initial_volumn = INITIAL_VOLUMN);
								//������Ĺ��캯������Ҫ������¹�����
								//1.ȷ��һ����ʼ����initial_volumn
								//2.�ÿ�����ͷ��������ͷ��p���n��ָ������
								//3.�Կ�����ͷ��n��Ϊn������ռ䣬Ȼ��Ϊn��ָ�����n������ռ䣬�Դ����ƣ�ֱ����������Ҫ��
								//4.����������ʹ��ָ����ȷ���á���Ҫ�ǵ����������p��
								//5.��дm_size=0, m_volumn=initial_volumn.

	~Priority_Linklist();		//���������������

	T top();					//�����������������ͷ

	int push(T element);		//�ӿ���������ȡ��һ��������飬��element������������d��󣬽����ƶ�����������е�ǡ��λ��
								//������������Ϊ�գ������increment()����
								//���Ԫ�ز���ʧ�ܣ�����-1.�ɹ�����,m_size++, ����0.

	int pop(T element);			//ɾ��������������ͷ��size--
								//���ԭ������������Ϊ�գ��򷵻�-1�����򷵻�0.

	bool empty();				//�����������Ϊ�գ��򷵻�true�����򷵻�false.

	void swap(Priority_Linklist<T> other);	//�����������������ò��������Բ�ʵ����һ��������ֱ�ӷ��أ�

	int size() { return(m_size); }
	int volumn() { return(m_volumn); }
};
