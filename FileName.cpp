#include <iostream>
using namespace std;

void setpotion(int count, int* PotionHP, int* PotionMP) {
	*PotionHP = count;
	*PotionMP = count;
}
// setpotion�̶�� �Լ��� ���� ������ �����ϴ� ����
// int* PotionHP�� int* PotionMp�� ���� HP�� MP ������ ������ �����ϴ� �������Դϴ�.
// count�� ������ ������ ��Ÿ����, �� ���� �� �����Ͱ� ����Ű�� ������ �����մϴ�.
// *PotionHP�� *PotionMP = count;�� ������ �����Ͱ� ����Ű�� ������ count ���� �Ҵ��մϴ�.
// �� �Լ��� ������ ������ �����ϴ� ����� �����մϴ�. �Ǵ� ���ÿ� ���� ������ ����
// ���� ��� PRG���ӿ��� �ʹݿ� ������ �⺻���� ���� ���� �� ó�� ��밡��.

int main() {
	const int size = 4; // const : ���, size�� �迭�� ũ�⸦ ��Ÿ����.
	int stat[size] = { 0 }; // state �迭�� 4���� ������ �ʱ�ȭ�Ǹ�, ������ ��Ҵ� 0���� �����ȴ�.
	// state [0] : hp, state [1] : mp, state [2] : potionhp, state [3] : potionmp

	//HP�� MP �Է�
	while (true) { // ���� ������ ����Ͽ� ��ȿ�� HP�� MP �Է��� ���� ������ �ݺ�
		cout << "HP�� �Է����ּ���: ";
		cin >> stat[0];
		cout << "MP�� �Է����ּ���: ";
		cin >> stat[1];

		if (stat[0] > 50 && stat[1] > 50) break; // �� ���� ������ ��� ������ �� ���� ����(���� �Ǹ� ���� Ż��)
		// &&�� "�׸���"�� �ǹ��ϸ�, �� ������ ��� ���� ���� ����ȴ�.
		// break;�� ������ �����ϴ� ������ �Ѵ�.
	}

	// ���ݷ�, ���� �Է�
	while (true) {
		cout << "���ݷ��� �Է����ּ���: ";
		cin >> stat[2];
		cout << "������ �Է����ּ���: ";
		cin >> stat[3];
		if (stat[2] > 0 && stat[3] > 0) break;
		cout << "���ݷ��̳� ������ ���� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���." << endl;
	}
	int choice = 0; // ������� ������ ������ ����, �޴� ��ȣ��	�����ϴµ� ���.
	int HPPotion = 0; // HP ���� ����
	int MPPotion = 0; // MP ���� ����
	// ���� ������ ������ 0���� �����Ѵ�.

	setpotion(10, &HPPotion, &MPPotion); // setPotion �Լ��� ȣ���Ͽ� HP�� MP ���� ������ 10���� ����
	// setPotion �Լ��� ������ ������ �����ϴ� ������ �Ѵ�.
	cout << "������ ���޵Ǿ����ϴ�. (HP, MP ���� �� 10��)" << endl;
	cout << "����������������������������������������������������" << endl;
	cout << "<���� ���� �ý���>" << endl;

	while (true) {
		cout << "1. HP ���� ��� \n";
		cout << "2. MP ���� ��� \n";
		cout << "3. HP ��ȭ \n";
		cout << "4. MP ��ȭ \n";
		cout << "5. ���� ��ų ��� \n";
		cout << "6. �ʻ�� ��� \n";
		cout << "7. �ڷΰ���\n";
		// ���� ���� : �޴��� ��� ����Ͽ� ����ڰ� ������ �� �ֵ��� �Ѵ�.
		cout << "��ȣ�� �������ּ��� : ";
		cin >> choice;

			if (choice == 7)
			{
				cout << "���α׷��� �����մϴ�." << endl;
				break; // ����ڰ� 7�� �����ϸ� ���α׷� ����
			}
		switch (choice) 
		{
		case 1: // HP ȸ��
			if (HPPotion <= 0)
			{
				cout << "������ �����մϴ�." << endl;
				continue; // ������ �����ϸ� ���� �ݺ����� �Ѿ, ������ ������ �޼���, ������ +20, ���� -1
			}
			stat[0] += stat[0] * 0.2; // ���� HP�� 20% ȸ��
			HPPotion--; // HP ���� ���� ����, ���������ڸ� ����Ͽ� ����
			cout << " HP�� 20% ȸ���Ǿ����ϴ�. ������ 1�� �����˴ϴ�." << endl;
			cout << "���� HP : " << stat[0] << endl; // ���� HP ���
			cout << "���� ���� �� : " << HPPotion << endl; // ���� ������ ���� ���
			break;
		
		case 2: // MP ȸ��
			if (MPPotion <= 0) 
			{
				cout << "������ �����մϴ�." << endl;
				continue; // ������ �����ϸ� ���� �ݺ����� �Ѿ
			}
			stat[1] += stat[1] * 0.2; // MP�� 20% ȸ��
			MPPotion--; // MP ���� ���� ����
			cout << "MP�� 20% ȸ���Ǿ����ϴ�. ������ 1�� �����˴ϴ�." << endl;
			cout << "���� MP: " << stat[1] << endl; // ���� MP ���
			cout << "���� ���� ��: " << MPPotion << endl; // ���� ������ ���� ���
			break;

		case 3: // HP ��ȭ
			stat[0] *= 2; // HP�� 2��� ����
			cout << "HP�� 2��� �����Ǿ����ϴ�." << endl;
			cout << "���� HP: " << stat[0] << endl; // ���� HP ���
			break;

		case 4: // MP ��ȭ
			stat[1] *= 2; // MP�� 2��� ����
			cout << "MP�� 2��� �����Ǿ����ϴ�." << endl;
			cout << "���� MP: " << stat[1] << endl; // ���� MP ���
			break;

		case 5: // ���� ��ų ���
			stat[2] -= 10; // ���ݷ� ����
			if (stat[1] < 50) 
			{
				cout << "��ų ����� �Ұ��մϴ�." << endl; // MP�� �����ϸ� ��ų ��� �Ұ�
			}
			else
			{
				stat[1] -= stat[1] * 0.5; // MP ����
				cout << "��ų�� ����Ͽ� MP�� 50% �Ҹ�Ǿ����ϴ�." << endl;
				cout << "���� MP: " << stat[1] << endl; // ���� MP ���
			}
				break;
			
		case 6: // �ʻ�� ���
			stat[1] -= stat[2] / 2; // MP�� 50% ����
			if (stat[1] <= 0)
			{
				cout << "��ų ����� �Ұ��մϴ�." << endl; // MP�� �����ϸ� ��ų ��� �Ұ�
			}
			else
			{
				cout << "��ų�� ����Ͽ� MP�� 50% �Ҹ�Ǿ����ϴ�." << endl;
				cout << "���� MP: " << stat[1] << endl; // ���� MP ���
			}
				break;
			
		default:
			cout << "�ٽ� �Է����ּ���." << endl;
			break;
			}
		}

			return 0;
	}



