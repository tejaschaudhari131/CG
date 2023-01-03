#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

class Transformation
{
	int triangle[2][3];
	int /*trans_matrix[3][3],*/trans_result[2][3];
	float /*rotation_matrix[3][3],*/rotation_result[2][3];
	float /*scalingmatrix[3][3],*/scaling_result[2][3];
	
	public:
		void get_triangle()
		{
			cout<<"\nEnter the co-ordinates of triangle:";
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<2;j++)
				{
					cin>>triangle[j][i];
				}
			}
		}
		
		void translation()
		{
			int tx,ty;
			cout<<"\nEnter tx and ty respectively:";
			cin>>tx>>ty;
			
			int trans[2] = {tx,ty};
			
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<2;j++)
				{
					trans_result[j][i] = triangle[j][i] + trans[j];
				}
			}
			
			//return trans_result;
			
			/*for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if(i==j)
					{
						triangle[j][i] = 1;
					}
					else if(j==2)
					{
						triangle[j][i] = trans[i];
					}
					else
					{
						triangle[j][i] = 0;
					}
				}
			}*/
			
		}
		
		void rotation()
		{
			int ch;
			float ang;
			cout<<"Choose the option for rotation:\n1]Clockwise\n2]Anti-clockwise\n";
			cin>>ch;
			cout<<"Enter the angle:";
			cin>>ang;
			float c = cos(ang*3.14/180);
			float s = sin(ang*3.14/180);
			if(ch==1)
			{
				for(int i=0;i<3;i++)
				{
					for(int j=0;j<2;j++)
					{
						if(j==0)
						{
							rotation_result[j][i] = (triangle[0][i]*c) - (triangle[1][i]*s);
						}
						else
						{
							rotation_result[j][i] = (triangle[0][i]*s) + (triangle[1][i]*c);
						}
					}
				}
			}
			else
			{
				for(int i=0;i<3;i++)
				{
					for(int j=0;j<2;j++)
					{
						if(j==0)
						{
							rotation_result[j][i] = (triangle[0][i]*c) + (triangle[1][i]*s);
						}
						else
						{
							rotation_result[j][i] = (triangle[1][i]*c) - (triangle[0][i]*s);
						}
					}
				}
			}
			
			//return rotation_result;	
		}

		void scaling()
		{
			float sx,sy;
			cout<<"\nEnter the scaling factor(x and y):";
			cin>>sx>>sy;
			
			float scf[2] = {sx,sy};
			
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<2;j++)
				{
					scaling_result[j][i] = triangle[j][i] * scf[j];
				}
			}
		}

		int* set_cordinates(int choice)
		{
			int nco[6];
			int index = 0;
			switch(choice)
			{
				case 1://Translation
					for(int i=0;i<3;i++)
					{
						for(int j=0;j<2;j++)
						{
							nco[index] = trans_result[j][i];
							index++;
						}
					}
					return nco;
				

				case 2://Rotation
					for(int i=0;i<3;i++)
					{
						for(int j=0;j<3;j++)
						{
							nco[index] = rotation_result[j][i];
							index++;
						}
					}
					return nco;

				case 3:
					for(int i=0;i<3;i++)
					{
						for(int j=0;j<3;j++)
						{
							nco[index] = scaling_result[j][i];
							index++;
						}
					}
					return nco;
			}
		}
};

int main()
{
	Transformation t1;
	t1.get_triangle();
	return 0;
}
