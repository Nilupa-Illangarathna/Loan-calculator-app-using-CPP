#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <conio.h>
#include <cmath>

using namespace std;

void PrintTable()
{
	cout<<"\n\n\n";
	cout<<"\t\t-----------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t|  Type  |   Loan Name   |   Customer's age   |   Monthly income   |   Max. Loan amount   |   Max Repay period   |   Annual interest    |"<<endl;
	cout<<"\t\t|        |               |                    |                    |                      |                      |    rate(%) FIXED     |"<<endl;
	cout<<"\t\t- ---------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t|    1   |    Vehicle    |   Between 18 to    |       Above        |      1,000,000.00    |          60          |          14          |"<<endl;
	cout<<"\t\t|        |               |      55 years      |       45,000       |                      |                      |                      |"<<endl;
	cout<<"\t\t- ---------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t|    2   |    Housing    |   Between 25 to    |       Above        |      2,500,000.00    |          60          |          8           |"<<endl;
	cout<<"\t\t|        |               |      55 years      |      100,000       |                      |                      |                      |"<<endl;
	cout<<"\t\t- ---------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t|    3   |    Eduation   |   Between 25 to    |       Above        |      1,500,000.00    |          28          |          6           |"<<endl;///////////////////////////////////////////////
	cout<<"\t\t|        |               |      35 years      |       45,000       |                      |                      |                      |"<<endl;
	cout<<"\t\t- ---------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t|    4   |    Senior     |      Above 60      |       Above        |       500,000.00     |          60          |         4.5          |"<<endl;
	cout<<"\t\t|        |    Citizen    |                    |       35,000       |                      |                      |                      |"<<endl;
	cout<<"\t\t- ---------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t|    5   |    Personal   |   Between 30 to    |       Above        |      2,000,000.00    |          60          |        14.5          |"<<endl;
	cout<<"\t\t|    6   |               |      55 years      |      100,000       |      3,000,000.00    |          84          |        16.2          |"<<endl;
	cout<<"\t\t- ---------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}

void GettingInputs(string &Name , int &Age , double &Income , int &LoanType , double &RequiredAmount , int &YearstoPay  ,  int &MonthsToPay)
{
	
	cout<<endl<<endl;
	cout<<"\t\tName of the customer : ";
	getline(cin,Name);
	cout<<"\t\tAge of the customer : ";
	cin>>Age;
	cout<<"\t\tCustomer's income : ";
	cin>>Income;
	
	PrintTable();
		
	cout<<"\n\n\t\tSelect The Loan type : ";
	cin>>LoanType;
	cout<<"\t\tEnter the loan amount : ";
	cin>>RequiredAmount;
	cout<<"\t\tRepay period in Years :";
	cin>>YearstoPay;
	cout<<"\t\tMonths format : ";
	cin>>MonthsToPay;
	cout<<endl;
}

bool EligibilityCheck(int age , double income , int requiredamount , int loantype , int monthstopay)
{
	if(loantype==1)
	{
		if(age<18 || 55<age)
		{
			return false;
		}
		if(income<45000)
		{
			return false;
		}
		if(1000000<requiredamount)
		{
			return false;
		}
		if(60<monthstopay)
		{
			return false;
		}
	}
	else if(loantype==2)
	{
		if(age<25 || 55<age)
		{
			return false;
		}
		if(income<100000)
		{
			return false;
		}
		if(2500000<requiredamount)
		{
			return false;
		}
		if(60<monthstopay)
		{
			return false;
		}
	}
	else if(loantype==3)
	{
		if(age<25 || 35<age)
		{
			return false;
		}
		if(income<45000)
		{
			return false;
		}
		if(1500000<requiredamount)
		{
			return false;
		}
		if(84<monthstopay) 
		{
			return false;
		}
	}
	else if(loantype==4)
	{
		if(age<60)
		{
			return false;
		}
		if(income<35000)
		{
			return false;
		}
		if(500000<requiredamount)
		{
			return false;
		}
		if(60<monthstopay) 
		{
			return false;
		}
	}
	else if(loantype==5)
	{
		if(30<age || age<55)
		{
			return false;
		}
		if(income<100000)
		{
			return false;
		}
		if(2000000<requiredamount)
		{
			return false;
		}
		if(60<monthstopay) 
		{
			return false;
		}
	}	
	else if(loantype==6)
	{
		if(30<age || age<55)
		{
			return false;
		}
		if(income<100000)
		{
			return false;
		}
		if(3000000<requiredamount)
		{
			return false;
		}
		if(84<monthstopay) 
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	return true;
}

double D_Calculation(int n , float InterestRate)
{
	double IR = InterestRate/(12*100);
	
	double D = (pow((1+IR) , n) - 1)/(IR*pow((1+IR),n));

	return D;
}

int main()
{
	while(true)
	{
		
		cout<<"\n\n";
		cout<<"\tyou want to apply for a loan? (y/n) : ";
		char Continue;
		cin>>Continue;
		system("cls");
		cout<<"\n\n";
		
		if(Continue!='y')
		{
			system("cls");
			cout<<"Exit";
			break;
		}
		else
		{
			cin.ignore();
			float InterestRate [6] = {14 , 8 , 6 , 4.5 , 14.5 , 16.2 };
			string LoanTypes [6] = {"Vehicle" , "Housing" , "Education" , "Senior Citizen" , "Personal" , "Personal"};
			int MaxRepayPeriods [6]= {60,60,84,60,60,84};
			
			string Name;
			int Age;
			double Income;
			int LoanType;
			double RequiredAmount;
			int YearstoPay;
			int MonthsToPay;
		
			GettingInputs(Name , Age , Income , LoanType , RequiredAmount , YearstoPay,  MonthsToPay);
			
			if(EligibilityCheck(Age , Income , RequiredAmount , LoanType , YearstoPay*12 + MonthsToPay))
			{
				double D = D_Calculation(YearstoPay*12 + MonthsToPay , InterestRate[LoanType-1]);

				double TotalMonthlyPayable = RequiredAmount/D;

				double LoanRemaining=double(RequiredAmount);
				float InterestOfTheLoan = InterestRate[LoanType-1]/(12*100);
				double TotalAmountHePays=0;
				double InterestEarnedByBank=0;
			
			
				
				//Creating the file
				ofstream file;
				string filename=Name+".txt";
				file.open(filename.c_str());
				file<<"Name of the customer : "<<Name<<endl;
				file<<"Selected loan : "<<LoanTypes[LoanType-1]<<endl;
				file<<"Maximum repay period allowed : "<<MaxRepayPeriods[LoanType-1]<<endl;
				file<<"Annual Interest Rate : "<<InterestRate[LoanType-1]<<endl;
				file<<"Requested loan ammount : "<<fixed<<setprecision(2)<<RequiredAmount<<endl;
				file<<"Requested repay period : "<<MonthsToPay<<endl;				
				file<<"\n\n";
				file<<"\t\t---------------------------------------------------------------------------------------"<<endl;
				file<<"\t\t       Month         Remaining loan        Interest         Repaid loan amount "<<endl;


				for(int i=0 ; i<YearstoPay*12 + MonthsToPay;i++)
				{
					double MonthlyInterest = LoanRemaining*InterestOfTheLoan;
					double LoanRepayForThisMonth = abs(TotalMonthlyPayable - MonthlyInterest);
					LoanRemaining-=LoanRepayForThisMonth;
					InterestEarnedByBank+=MonthlyInterest;
					TotalAmountHePays+=TotalMonthlyPayable;	

					file<<"\t\t---------------------------------------------------------------------------------------"<<endl;
					file<<"\t\t         "<<i<<"                 "<<fixed<<setprecision(2)<<abs(LoanRemaining)<<"            "<<MonthlyInterest<<"              "<<LoanRepayForThisMonth<<endl;
				}

				cout<<endl<<endl;
				cout<<"\t\t\t\t\t\t-----------------------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t\t\t|  Monthly repay amount                         : "<<fixed<<setprecision(2)<<TotalMonthlyPayable<<"                  |"<<endl; 
				cout<<"\t\t\t\t\t\t|  Total amount of money that the customer pays : "<<fixed<<setprecision(2)<<TotalAmountHePays<<"                |"<<endl;
				cout<<"\t\t\t\t\t\t|  Total amount of interest earned by the bank  : "<<fixed<<setprecision(2)<<InterestEarnedByBank<<"                 |"<<endl;
				cout<<"\t\t\t\t\t\t-----------------------------------------------------------------------------"<<endl;
				
				file<<endl<<endl<<endl;

				file<<"\t\t\t\t\t\t-----------------------------------------------------------------------------"<<endl;
				file<<"\t\t\t\t\t\t|  Monthly repay amount                         : "<<fixed<<setprecision(2)<<TotalMonthlyPayable<<"                  |"<<endl; 
				file<<"\t\t\t\t\t\t|  Total amount of money that the customer pays : "<<fixed<<setprecision(2)<<TotalAmountHePays<<"                |"<<endl;
				file<<"\t\t\t\t\t\t|  Total amount of interest earned by the bank  : "<<fixed<<setprecision(2)<<InterestEarnedByBank<<"                 |"<<endl;
				file<<"\t\t\t\t\t\t-----------------------------------------------------------------------------"<<endl;
				
				
				
			}
			else
			{
				cout<<"\n\n\t\t\t\t\tYou are not eligible to apply for this loan "<<endl<<endl<<endl<<endl;
				
				ofstream file;
				string filename=Name+".txt";
				file.open(filename.c_str());
				file<<"Name of the customer : "<<Name<<endl;
				file<<"Selected loan : "<<LoanTypes[LoanType-1]<<endl;
				file<<"Maximum repay period allowed : "<<MaxRepayPeriods[LoanType-1]<<endl;
				file<<"Annual Interest Rate : "<<InterestRate[LoanType-1]<<endl;
				file<<"Requested loan ammount : "<<fixed<<setprecision(2)<<RequiredAmount<<endl;
				file<<"Requested repay period : "<<MonthsToPay<<endl;
				file<<endl<<endl;
				file<<"\t\tYOU ARE NOT ELIGIBLE TO APPLY FOR THIS LOAN..";
				

			}
			
		
			
			
		}

		

	}
	
	
	
	return 0;
}
