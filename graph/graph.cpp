#include <iostream>
#include <vector>
#include <tuple>
#define VSIZE 500
using namespace std;

int main() {

	int VertexN; //������ ����
	int EdgeN;  //������ ����
	cin >> VertexN >> EdgeN;
	vector<tuple<int, int, int>> Edge(EdgeN);

	//������ ������ ����
	for (int i = 0; i < EdgeN; i++) {
		int A, B, W; //A���� B�� W�� ����ġ�� ������.
		scanf("%d %d",&A,&B,&W);
		Edge.push_back(make_tuple(A, B, W));
	}
	//�������
	int graphMatrix[VSIZE + 1][VSIZE + 1]; //�ִ� ������ŭ�̸� ����
	for (auto i : Edge) {
		int V1 = get<0>(i); //A
		int V2 = get<1>(i); //B
		int W = get<2>(i); //Weight
		//����� ���
		graphMatrix[V1][V2] = W;
		graphMatrix[V2][V1] = W;
	}
	
	//��������Ʈ
	vector<pair<int, int>> graphList[VSIZE + 1];
	for (auto i : Edge) {
		int V1 = get<0>(i); //A
		int V2 = get<1>(i); //B
		int W = get<2>(i); //Weight
						   //����� ���
		graphList[V1].push_back(make_pair(V2, W));
		graphList[V2].push_back(make_pair(V1, W));
	}


}