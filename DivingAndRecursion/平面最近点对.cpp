double Distance(point a,point b)
{
/* ��������� */
}
void QuickSort(point p[], int start, int end)
{
/* ���� */
}
struct point
{
	int x, y;
};
double Closest(point S[], int low, int high, point & a, point & b){
	double d1, d2, d3, d;
	int mid, i, j, index;
 
	//��ŵ㼯��P1��P2
	point P[30];
 
	//ֻ��������
	if (high-low==1)
	{
		a = S[low];
		b = S[high];
		return Distance(S[low], S[high]);
	}
 
	//ֻ��������
	if (high-low==2)
	{
		d1 = Distance(S[low], S[low + 1]);
		d2 = Distance(S[low + 1], S[high]);
		d3 = Distance(S[low], S[high]);
 
		if ((d1 < d2) && (d1 < d3)){
			a = S[low];
			b = S[low + 1];
			 
			return d1;
		}
			
		else if (d2 < d3){
			a = S[low+1];
			b = S[high];
			 
			return d2;
		}
			
		else{
			 
			a = S[low];
			b = S[high];
			return d3;
		}
			
	}
 
	//���ڵ㿪ʼ��������
	mid = (low + high) / 2;
	//�ݹ����������1
	d1 = Closest(S, low, mid,a,b);
	//�ݹ����������2
	point ar, br;
	d2 = Closest(S, mid + 1, high,ar,br);
	if (d1<d2)
	{
		d = d1;
	}
	else
	{
		a = ar;
		b = br;
		d = d2;
	}
 
	index = 0;
	//��������P1
	for (i = mid; (i >= low) && ((S[mid].x - S[i].x) < d); i--){
		P[index++] = S[i];
	}
	//��������P2
	for (i = mid + 1; (i <= high) && ((S[i].x - S[mid].x) < d); i++){
		P[index++] = S[i];
	}
 
	//�����������е����ݰ�Y�������������
	QuickSort(P, 0, index - 1);
 
	for (i = 0; i < index; i++){
		for (j = i + 1; j < index; j++){
			if ((P[j].y-P[i].y)>=d)
			{
				break;
			}
			else
			{
				d3 = Distance(P[i], P[j]);
				 
				if (d3<d)
				{
					a = P[i];
					b = P[j];
					d = d3;
				}
			}
		}
	}
	return d;
}

