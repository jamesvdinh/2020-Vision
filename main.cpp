#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// program with user input to show cases in a region
int main()
{
    string states[51] = {" ", "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Deleware", "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming"};
    
    int totalcasesstate[51] = {0, 163456, 9182, 224084, 91312, 851228, 76595, 60038, 21827, 728921, 329032, 13300, 47088, 316546, 131493, 98068, 64714, 78456, 170878, 5665, 130159, 137701, 147816, 109312, 103681, 141003, 17399, 50059, 84593, 8970, 212013, 32241, 471696, 227431, 26627, 166102, 97088, 36526, 174329, 26294, 155676, 27215, 211003, 812191, 83290, 1846, 156372, 92560, 17707, 155818, 7335};

    int populationstate[51] = {0, 4858979,	738432,	6828065,	2978204,	39144818,	5456574,	3590886,	945934,	20271272,	10214860,	1431603,	1654930,	12859995,	6619680,	3123899,	2911641,	4425092,	4670724,	1329328,	6006401,	6794422,	9922576,	5489594,	2992333,	6083672,	1032949,	1896190,	2890845,	1330608, 8958013,	2085109,	19795791,	10042802,	756927,	11613423,	3911338,	4028977,	12802503,	1056298,	4896146,	858469,	6600299,	27469114,	2995919,	626042,	8382993,	7170351,	1844128, 5771337, 586107};

    double percentageinfected[51];

    for (int z = 1; z <= 51; z++)
    {
      int cases = totalcasesstate[z];
      int pop = populationstate[z];
      double result = (1.0*cases)/ (1.0*pop);
      percentageinfected[z] = result;
    }

    string riskfactorall[51];
    for (int r = 1; r <= 51; r++)
    {
      if (percentageinfected[r] >= 0.03)
      {
        riskfactorall[r] = "risky";
      }
      if (percentageinfected[r] <= 0.01)
      {
        riskfactorall[r] = "safe";
      }
      if (percentageinfected[r] > 0.01 && percentageinfected[r] < 0.03)
      {
        riskfactorall[r] = "moderate";
      }
    }


    int s = 0, totalcases = 0, option = 0, population = 0;
    double percentcorona = 0.0;
    string state, capital, riskfactor = "none";
    do
    {
      cout << "Choose option to view COVID-19 stats (1.Table, 2.Specified Region Search): ";
      cin >> option;
    } while (option < 1 || option > 2);

    if (option == 1)
    {
      cout << endl;
      cout << "State                Total Cases     Population      Risk Factor      Percent Infected" << endl;
      cout << "---------------------------------------------------------------------------------------" << endl;
      for (int i = 1; i < 51; i++)
      {
        cout << fixed;
        cout << left << setw(14) << states[i] << "       " << left << setw(9) << totalcasesstate[i] << "       " << left << setw(9) << populationstate[i] << "       " << left << setw(9) << riskfactorall[i] << "        " << left << setw(9) << setprecision(3) << 100.0*percentageinfected[i] << "%" << endl << endl;
      }
      cout << "Statistics from NPR.org, October 10, 2020" << endl;
      cout << "*Risk Factor is based on relative risk compared to the other states" << endl << endl;

      // show risk factor states
      int option2;
      do
      {
        do
        {
        cout << "Choose a Risk Factor to view states (1.Safe, 2.Moderate, 3.Risky)(0 to stop): ";
        cin >>option2;
        } while(option2<0||option2>3);
        if(option2==1)
        {
          for(int k = 1; k<51; k++)
          {
            if(riskfactorall[k] == "safe")
            {
              cout<<100*percentageinfected[k];
              cout<<"% ";
              cout<<states[k]<<endl;
            }
          }
          continue;
        }
        if(option2==2)
        { 
          for(int k = 1; k<51; k++)
          {
            if(riskfactorall[k] == "moderate")
            {
              cout<<100*percentageinfected[k];
              cout<<"% ";
              cout<<states[k]<<endl;
            }
          }
          continue;
        }
        if(option2==3)
        {
          for(int k = 1; k<51; k++)
          {
            if(riskfactorall[k] == "risky")
            {
              cout<<100*percentageinfected[k];
              cout<<"% ";
              cout<<states[k]<<endl;
            }
          }
          continue;
        }
        else
          break;
      } while (option2 != 0);
    }
    if (option == 2)
    {
      do
      {
       do
        {
          cout << "                               United States (1-50)                                     " << endl;
          cout << "---------------------------------------------------------------------------------------"<< endl;
          cout << "1.Alabama      11.Hawaii     21.Massachusetts    31.New Mexico      41.South Dakota" << endl;
          cout << "2.Alaska       12.Idaho      22.Michigan         32.New York        42.Tennessee" << endl;
          cout << "3.Arizona      13.Illinois   23.Minnesota        33.North Carolina  43.Texas " << endl;
          cout << "4.Arizona      14.Indiana    24.Mississippi      34.North Dakota    44.Utah" << endl;
          cout << "5.California   15.Iowa       25.Missouri         35.Ohio            45.Vermont" << endl;
          cout << "6.Colorado     16.Kansas     26.Montana          36.Oklahoma        46.Virginia" << endl;
          cout << "7.Connecticut  17.Kentucky   27.Nebraska         37.Oregan          47.Washington" << endl;
          cout << "8.Deleware     18.Louisiana  28.Nevada           38.Pennsylvania    48.West Virginia" << endl;
          cout << "9.Florida      19.Maine      29.New Hampshire    39.Rhode Island    49.Wisconsin" << endl;
          cout << "10.Georgia     20.Maryland   30.New Jersey       40.South Carolina  50.Wyoming" << endl << endl;
          cout << "Choose 51 to edit a state" << endl;

          cout << "Choose a state (0.End): ";
          cin >> s;
        } while (s < 0 || s > 51);

        if (s == 51)
        {
          int statechoice;
          do
          {
            cout << "Which state do you want to edit? ";
            cin >> statechoice;
            cout << endl;
          } while (statechoice < 0 || statechoice > 50);
          int editchoice;
          int newpop, temppop = populationstate[statechoice];
          int newcases, tempcases = percentageinfected[statechoice];
          do 
          {
            cout << "What would you like to change? (1.Population, 2.Total Cases, 3.Reset): ";
            cin >> editchoice;
          } while (editchoice < 1 || editchoice > 3);
          if (editchoice == 1)
          {
            cout << "Type in new Population: ";
            cin >> newpop;
            temppop = populationstate[statechoice];
            populationstate[statechoice] = newpop;
          }
          if (editchoice == 2)
          {
            cout << "Type in new Total Cases: ";
            cin >> newcases;
            tempcases = totalcasesstate[statechoice];
            totalcasesstate[statechoice] = newcases;
          }
          if (editchoice == 3)
          {
            populationstate[statechoice] = temppop;
            totalcasesstate[statechoice] = tempcases;
          }
          percentageinfected[statechoice] = (1.0*totalcasesstate[statechoice])/ (1.0*populationstate[statechoice]);
          if (percentageinfected[statechoice] >= 0.03)
          {
            riskfactorall[statechoice] = "risky";
          }
          if (percentageinfected[statechoice] <= 0.01)
          {
            riskfactorall[statechoice] = "safe";
          }
          if (percentageinfected[statechoice] > 0.01 && percentageinfected[statechoice] < 0.03)
          {
            riskfactorall[statechoice] = "moderate";
          }

          cout << endl;
          cout << "State                Total Cases     Population      Risk Factor      Percent Infected" << endl;
          cout << "----------------------------------------------------------------------------------------" << endl;
          cout << fixed;
          cout << left << setw(14) << states[statechoice] << "       " << setw(9) << totalcasesstate[statechoice] << "       " << setw(9) << populationstate[statechoice] << "       " << setw(9) << riskfactorall[statechoice] << "        " << setw(1) << setprecision(3) << 100.0*percentageinfected[statechoice] << "%" << endl << endl;

          continue;
        }

        state = states[s];
        totalcases = totalcasesstate[s];
        population = populationstate[s];
        percentcorona = percentageinfected[s];
        riskfactor = riskfactorall[s];

        if (s != 0 && s != 51)
        {
          cout << endl;
          cout << "State                Total Cases     Population      Risk Factor      Percent Infected" << endl;
          cout << "----------------------------------------------------------------------------------------" << endl;
          cout << fixed;
          cout << left << setw(14) << state << "       " << setw(9) << totalcases << "       " << setw(9) << population << "       " << setw(9) << riskfactor << "        " << setw(1) << setprecision(3) << 100.0*percentcorona << "%" << endl << endl;
          continue;
        }
        else
        {
          break;
        }
      } while (s != 0);
    }

    return 0;
}
