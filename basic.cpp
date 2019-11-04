#include<ctime>
#include<random>
namespace Random{
	typedef unsigned long long int u64;
	struct RandEngine{
		inline u64 get()
		{
			static std::mt19937 mt(time(0));
			return (u64)mt();
		}
	};
	inline u64 randInt(u64 l,u64 r)
	{
		static RandEngine rd;
		return l+rd.get()%(r-l+1);
	}
	inline double randFloat(int precision)
	{
		static RandEngine rd;
		double res=0.0,cur=0.1;
		int x=1;
		while(x<=precision)
		{
			res+=(double)(rd.get()%10)*cur;
			cur*=0.1,x++;
		}
		return res;
	}
	inline double randFloat(double l,double r,int precision)
	{
		static RandEngine rd;
		double res=0.0,cur=0.1;
		int x=1;
		u64 mul=1,p;
		while(x<=precision)
		{
			mul*=10,x++;
		}
		x=1;
		while(x<=precision)
		{
			res+=(double)(rd.get()%10)*cur;
			cur*=0.1,x++;
		}
		res=l+(r-l)*res,p=(u64)(res*(double)mul);
		return (double)p/mul;
	}
}
