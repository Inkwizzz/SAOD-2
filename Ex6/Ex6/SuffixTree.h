#pragma once
#include "STreeNode.h"


// ����� ����������� ������� ��� �������� ������ � ���������� ������ ���������
class SuffixTree
{
	static const char* pszData;	// ��������� �� ����� � ������� ����� �����
	static int N;				// ����� ����� ������
	static STNode* root;		// �������� ������� ������
	public:
		// ��������� ����������� �� ���������, �������� ����������� � ������������.
		SuffixTree() = delete;
		SuffixTree(SuffixTree const&) = delete;
		SuffixTree& operator=(SuffixTree const&) = delete;

		// ��������� ���� � ������ ������ ���������
		static void Init(const char* s)
		{
			N = strlen(s);
			pszData = s;
			root = new STNode();

			// ��������� ��� �������� � ������
			for (int i = 0; i < N; i++)
				addSuffix(i);
		}
		static STNode* GetRoot()
		{
			return root;
		}
		// ���������� ������ ������, ��� �������� ��������� ������
		static int GetSize()
		{
			return N;
		}
		// ���������� ��������� �� �����, ��� �������� ��������� ������
		static const char* GetData()
		{
			return pszData;
		}
		static bool Contains(const char* s)
		{
			STNode* node = root;
			const char* p = s;
			while (node)
			{
				STLink* link = node->GetLink(*p);
				if (!link)
					return false;
				const char* label = *link;
				int len = link->Length();
				for (int i = 0; i < len; i++) 
				{
					if (*p != label[i])
						return false;
					p++;
					if (!*p) {

						STNode* target = link->GetNode();
						if (!target)
							return true;
						else
							return false;
					}
				}
				node = link->GetNode();
			}
			return false;
		}
	private:
		// ��������� �������, ������� ���������� � ������� n � ������ pszData.
		static void addSuffix(int n)
		{
			if (n < 0 || n >= N)
				throw out_of_range("index out of range");

			// ������ ����� ������� ����� ���� ���� - ����� ������ ������� ������ ��������;
			// ������� ����� � ������ ������� ��������.
			STLink* pLnk = new STLink(pszData + n, N - n);
			pLnk->SetTarget(new STreeNode(n));

			STNode* node = root;
			while (1)
			{
				// ����� ����, � ������� ��� ��������������� �����
				if (node->GetLink(pszData[n]) == 0)
				{
					node->SetLink(pLnk);
					break;
				}
				else // ����������� �����
				{
					STLink* pLnkCurrent = node->GetLink(pszData[n]);
					int k = pLnkCurrent->PrefixLen(*pLnk);
					// ����� ��������� �������� ��������� ��������
					// �������� �������� ���� �� �����, �.�. ������� ������������� ���������� �������� (\xFF).
					if (k == pLnkCurrent->Length())
					{
						// ��������� ��������� ����� ��������, ������� ������� � ������� �����:
						// 1. �������� ����� �������� �����
						pLnk->LTruncate(k);
						// 2. �������� ������ �������� �� ����� ����������
						n += k;
						// ����� �������� ���� ����� � �������� ��������.
						node = pLnkCurrent->GetNode();
					}
					// ���� ������ ��������� ���������� ������� � �����.
					// ����� ������� ����� ���� � �������� ��� � ������� ����� � ������� k
					else
					{
						// ������� ����� ����
						STreeNode* pnewNode = new STreeNode();

						//� ����� ����� (� ���� ����� �� ����� �����, ������� ����� � �������� ����)
						STLink* pLnkTail = new STLink(*pLnkCurrent);
						// ��������� ���� ����� �����
						pLnkTail->LTruncate(k);
						// ... � ������ ������
						pLnkCurrent->RTruncate(k);
						// �������� ����� �������� �����
						pLnk->LTruncate(k);
						// �������� ������ �������� �� ����� ����������
						n += k;
						// �������� � ������ ����� ����
						pLnkCurrent->SetTarget(pnewNode);
						// � ������ ����� �������� ������� �����
						pnewNode->Node.SetLink(pLnkTail);
						// ���������� � ���� ������� ������������ ��������
						pnewNode->Node.SetLink(pLnk);
						break;
					}
				}
			}
		}
};

