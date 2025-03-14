#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
using namespace std;

string Coin;

bool ChooseCoinAndTopic(void);
void ChooseTopic(void);

enum enChooseCoin {Dollar = 1, EgyptianPound = 2, Euro = 3, Sterling = 4, SaudiRiyal = 5, Exit = 6};

enum enChooseTopic {IncomeStatement = 1, StatementOfRetainedEarnings = 2, BalanceSheet = 3, GoBackChooseCoin = 4};

enum enChooseModeIncomeStatement {MultiStageIncomeStatemectSimple = 1, MultiStageIncomeStatemectMorethananunknown = 2
, TheRateOfReturnOfTheStock = 3, PercentageOfControllingOwners = 4, PercentageOfNonControllingOwners = 5,
PreparingExcludedOperations = 6, StatementOfComprehensiveIncome = 7, GoBack = 8};

enum enChooseCumulativeEffectsOfDifferencesAccountingMethods {DifferencesBetweenCreditAndDebit = 1, SystemDifferences = 2};

enum enChooseStageInBalanceSheet {CurrentAsstes = 1, NonCurrentAsstes = 2, Liabilities = 3, OwnerIsEquity = 4, GoBAck = 5};

bool TOrF(string S){
short Flag;
do{
cout << S;
cin >> Flag;
while(cin.fail()){
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << S;
cin >> Flag;
}
}while(Flag != 1 && Flag != 0);

return Flag;
}

short ReadNumber(string S, short From, short To){
short Number;
do{
cout << S;
cin >> Number;
while(cin.fail()){
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << S;
cin >> Number;
}
if(Number < From || Number > To){cout << "    Error, Choose Number From " << From << " To " << To << endl;}
}while(Number < From || Number > To);

return Number;
}

double ReadNumberTex(string S){
double Number;
cout << S;
cin >> Number;
while(cin.fail()){
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << S;
cin >> Number;
}

return Number;
}

double ReadNumber(string S){
double Number;
cout << S << endl;
cout << "    ";
cin >> Number;
while(cin.fail()){
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "    Number Please: ";
cin >> Number;
}

return Number;
}

bool YOrN(string S){
char C;
do{
cout << S;
cin >> C;

}while(C != 'Y' && C != 'y' && C != 'N' && C != 'n');
if(C == 'Y' || C == 'y'){return 1;}
if(C == 'N' || C == 'n'){return 0;}

}

void PrintMultiStageIncomeStatement(void){
cout << "          ====================================================================" << endl;
cout << "         |                     Multi-Stage Income Statement                   |" << endl;
cout << "          ====================================================================" << endl;
}

void PrintfOperationalOperations(void){
cout << "    _________________________________________________" << endl;
cout << "   |             Operational Operations              |" << endl;
cout << "   |_________________________________________________|" << endl;
}

void PrintGrossProfit(int GrossPrefit){
cout << "    __________________________________" << endl;
cout << "    Gross Profit: " << GrossPrefit << Coin << endl;
cout << "    __________________________________" << endl;

}

double Other_Expenses(void){
double OtherExpenses = 0;
do{
double Count = ReadNumber("    Other Expenses: ");
OtherExpenses += Count;
if(Count == 0){break;}
}while(YOrN("    Are There Other Losses? Y/N: "));

return OtherExpenses;
}

double Any_Gains(void){
double AnyGains = 0;
do{
double Count = ReadNumber("    Any Gains: ");
AnyGains += Count;
if(Count == 0){break;}
}while(YOrN("    Are There Other Gains? Y/N: "));

return AnyGains;
}

double Net_income_from_operational_processes(double GrossPrefit, double SellingExpenses, double AdministratorExpenses, double OtherExpenses, double AnyGains){
//double Netincomefromoperationalprocesses = GrossPrefit - SellingExpenses - AdministratorExpenses - OtherExpenses + AnyGains;
return GrossPrefit - SellingExpenses - AdministratorExpenses - OtherExpenses + AnyGains;

}

void PrintNetincomefromoperationalprocesses(double Netincomefromoperationalprocesses){
cout << "    __________________________________________________" << endl;
cout << "    Net income from operational processes: " << Netincomefromoperationalprocesses << Coin << endl;
cout << "    __________________________________________________" << endl;
}

void PrintFinancingOperations(void){
cout << "    _________________________________________________" << endl;
cout << "   |               Financing Operations              |" << endl;
cout << "   |_________________________________________________|" << endl;
}

double Net_Income_from_Continuingoperations_Before_Tax(double Netincomefromoperationalprocesses, double FinancingInteestExpense){
//double NetIncomefromContinuingoperationsBeforeTax = Netincomefromoperationalprocesses - FinancingInteestExpense;
return Netincomefromoperationalprocesses - FinancingInteestExpense;
}

void PrintNetIncomefromContinuingoperationsBeforeTax(double NetIncomefromContinuingoperationsBeforeTax){
cout << "    __________________________________________________" << endl;
cout << "    Net Income from Continuing operations Before Tax: " << NetIncomefromContinuingoperationsBeforeTax << Coin << endl;
cout << "    __________________________________________________" << endl;

}

double Net_Income_from_Continuingoperations_After_Tax(double NetIncomefromContinuingoperationsBeforeTax, double Tax){
//double NetIncomefromContinuingoperationsAfterTax = NetIncomefromContinuingoperationsBeforeTax - (NetIncomefromContinuingoperationsBeforeTax * Tax);
return NetIncomefromContinuingoperationsBeforeTax - (NetIncomefromContinuingoperationsBeforeTax * Tax);
}

void PrintNetIncomefromContinuingoperationsAfterTax(double NetIncomefromContinuingoperationsAfterTax){
cout << "    __________________________________________________" << endl;
cout << "    Net Income from Continuing operations After tax: " << NetIncomefromContinuingoperationsAfterTax << Coin << endl;
cout << "    __________________________________________________" << endl;
}

void PrintExcludedOperations(void){
cout << "    _________________________________________________" << endl;
cout << "   |               Excluded Operations               |" << endl;
cout << "   |_________________________________________________|" << endl;
}

float Tax_(string S){
float Tax = ReadNumberTex(S);
Tax /= 100;
return Tax;
}

float ReverseTax_(float Tax){
float ReverseTax = 1 - Tax;
return ReverseTax;
}

double Filtering_(double Tax){
bool Flag = TOrF("    Gain or loss in liquidating one of the production lines? Gain = 1, Loss = 0: ");
double Filtering = ReadNumber("    Filtering one of the production lines? ");
float ReverseTax = ReverseTax_(Tax);
Filtering *= ReverseTax;
if(!Flag){Filtering *= -1;}

return Filtering;
}

double NetIncome_(double NetIncomefromContinuingoperationsAfterTax, double Filtering){
return NetIncomefromContinuingoperationsAfterTax + Filtering;
}

void PrintNetIncome(double NetIncome){
cout << "    ==================================" << endl;
cout << "    Net Income: " << NetIncome << Coin << endl;
cout << "    ==================================" << endl;
}

double GrossPrefit_(double NetSales, double CostOfSalesSold){
return NetSales - CostOfSalesSold;
}

void Mult_iStage_Income_Statement_Simple(void){
system("cls");

PrintMultiStageIncomeStatement();


cout << endl;

PrintfOperationalOperations();

double NetSales = ReadNumber("    Net Sales: ");
double CostOfSalesSold = ReadNumber("    Cost Of Sales Sold: ");

double GrossPrefit = GrossPrefit_(NetSales, CostOfSalesSold); //NetSales - CostOfSalesSold;

PrintGrossProfit(GrossPrefit);

double SellingExpenses =  ReadNumber("    Selling Expenses: ");
double AdministratorExpenses = ReadNumber("    Administrator Expenses: ");

double OtherExpenses = Other_Expenses();

double AnyGains = Any_Gains();

double Netincomefromoperationalprocesses = Net_income_from_operational_processes(GrossPrefit, SellingExpenses, AdministratorExpenses, OtherExpenses, AnyGains);

PrintNetincomefromoperationalprocesses(Netincomefromoperationalprocesses);

cout << endl;

PrintFinancingOperations();

double FinancingInteestExpense = ReadNumber("    Financing Inteest Expense: ");

double NetIncomefromContinuingoperationsBeforeTax = Net_Income_from_Continuingoperations_Before_Tax(Netincomefromoperationalprocesses, FinancingInteestExpense);

PrintNetIncomefromContinuingoperationsBeforeTax(NetIncomefromContinuingoperationsBeforeTax);

double Tax = Tax_("    Tax rate: %");

double NetIncomefromContinuingoperationsAfterTax = Net_Income_from_Continuingoperations_After_Tax(NetIncomefromContinuingoperationsBeforeTax, Tax);

PrintNetIncomefromContinuingoperationsAfterTax(NetIncomefromContinuingoperationsAfterTax);

PrintExcludedOperations();

double Filtering = Filtering_(Tax);

double NetIncome = NetIncome_(NetIncomefromContinuingoperationsAfterTax, Filtering);

PrintNetIncome(NetIncome);

system("pause");
}

double NetSales_(void){
bool Flag = YOrN("    Are net sales calculated? Y/N: ");
if(Flag){
return ReadNumber("    Net Sales: ");
}
double TotalSales = ReadNumber("    Total sales: ");
double SalesReturnsAndWithdrawals = ReadNumber("    Sales returns and withdrawals: ");
double AllowedDiscount = ReadNumber("    Allowed discount: ");
return TotalSales - SalesReturnsAndWithdrawals - AllowedDiscount;
}

double NetPurchases_(void){
bool Flag = YOrN("    Are net purchases calculated? Y/N: ");
if(Flag){
return ReadNumber("    Net purchases: ");
}
double TotalPurchases = ReadNumber("    Total purchases: ");
double PurchaseReturnsAndSurveys = ReadNumber("    Purchase returns and surveys: ");
double DiscountEarned = ReadNumber("    Discount earned: ");
double TransferBanksAbroad = ReadNumber("    Transfer banks abroad: ");
return TotalPurchases - PurchaseReturnsAndSurveys - DiscountEarned + TransferBanksAbroad;
}

void PrintNetPurchases(double NetPurchases){
cout << "    ____________________" << endl;
cout << "    Net Purchases: " << NetPurchases << Coin << endl;
cout << "    ____________________" << endl;

}

double CostOfSalesSold_(){
double NetPurchases = NetPurchases_();
PrintNetPurchases(NetPurchases);

bool Flag = YOrN("    Is cost of goods sold calculated? Y/N: ");
if(Flag){
return ReadNumber("    Cost Of Sales Sold: ");
}
double BeginningInventory = ReadNumber("    Beginning inventory: ");
double AtTheEndOfThePeriod = ReadNumber("    Inventory at the end of the period: ");
return BeginningInventory + NetPurchases - AtTheEndOfThePeriod;
}

void PrintNetSales(double NetSales){
cout << "    ____________________" << endl;
cout << "    Net Sales: " << NetSales << Coin << endl;
cout << "    ____________________" << endl;

}

void PrintCostOfSalesSold(double CostOfSalesSold){
cout << "    ____________________" << endl;
cout << "    Cost Of SalesSold: " << CostOfSalesSold << Coin << endl;
cout << "    ____________________" << endl;

}

void Mult_iStage_Income_Statement_More_than_an_un_known(void){
system("cls");

PrintMultiStageIncomeStatement();

cout << endl;

PrintfOperationalOperations();

double NetSales = NetSales_();

PrintNetSales(NetSales);

double CostOfSalesSold = CostOfSalesSold_();

PrintCostOfSalesSold(CostOfSalesSold);

double GrossPrefit = GrossPrefit_(NetSales, CostOfSalesSold); //NetSales - CostOfSalesSold;

PrintGrossProfit(GrossPrefit);

double SellingExpenses =  ReadNumber("    Selling Expenses: ");
double AdministratorExpenses = ReadNumber("    Administrator Expenses: ");

double OtherExpenses = Other_Expenses();

double AnyGains = Any_Gains();

double Netincomefromoperationalprocesses = Net_income_from_operational_processes(GrossPrefit, SellingExpenses, AdministratorExpenses, OtherExpenses, AnyGains);

PrintNetincomefromoperationalprocesses(Netincomefromoperationalprocesses);

cout << endl;

PrintFinancingOperations();

double FinancingInteestExpense = ReadNumber("    Financing Inteest Expense: ");

double NetIncomefromContinuingoperationsBeforeTax = Net_Income_from_Continuingoperations_Before_Tax(Netincomefromoperationalprocesses, FinancingInteestExpense);

PrintNetIncomefromContinuingoperationsBeforeTax(NetIncomefromContinuingoperationsBeforeTax);

float Tax = Tax_("    Tax rate: %");

double NetIncomefromContinuingoperationsAfterTax = Net_Income_from_Continuingoperations_After_Tax(NetIncomefromContinuingoperationsBeforeTax, Tax);

PrintNetIncomefromContinuingoperationsAfterTax(NetIncomefromContinuingoperationsAfterTax);

PrintExcludedOperations();

double Filtering = Filtering_(Tax);

double NetIncome = NetIncome_(NetIncomefromContinuingoperationsAfterTax, Filtering);

PrintNetIncome(NetIncome);

system("pause");

}

void PrintIntermediateAccounting(void){
cout << "         +====================================================================+" << endl;
cout << "         |                       Intermediate Accounting                      |" << endl;
cout << "         + ===================================================================+" << endl;
}

void PrintMainChooseModeIncomeStatement(void){
cout << "    ==========================================================" << endl;
cout << "    Choose the mode" << endl;
cout << "    ==========================================================" << endl;
cout << "    [1] Mult iStage Income Statement Simple." << endl;
cout << "    [2] Mult iStage Income Statement More than an un known." << endl;
cout << "    [3] The rate of return of the stock." << endl;
cout << "    [4] Percentage Of Controlling Owners." << endl;
cout << "    [5] Percentage Of Non-Controlling Owners." << endl;
cout << "    [6] Preparing Excluded Operations." << endl;
cout << "    [7] Statement of comprehensive income." << endl;
cout << "    [8] Go Back." << endl;
cout << "    ==========================================================" << endl;
}

void PrintTheRateOfReturnOfTheStock(void){
cout << "          ____________________________________________________________________" << endl;
cout << "         |                   The rate of return of the stock                  |" << endl;
cout << "         |____________________________________________________________________|" << endl;

}

double TheRateOfReturnOfTheStock_(void){
double FinalNetIncome = ReadNumber("    Final net income: ");
double DistributionOfPreferredShares = ReadNumber("    Distribution of preferred shares: ");
double DistributionOfCommonShares = ReadNumber("    Distribution of common shares: ");
return (FinalNetIncome - DistributionOfPreferredShares) / DistributionOfCommonShares;
}

void PrintOutputTheRateOfReturnOfTheStock(double TheRateOfReturnOfTheStock){
cout << "    ==============================================" << endl;
cout << "    OutPut The rate of return of the stock: " << TheRateOfReturnOfTheStock << Coin << " / stock" << endl;
cout << "    ==============================================" << endl;
}

void The_Rate_Of_Return_Of_The_Stock(void){
system("cls");
PrintMultiStageIncomeStatement();
cout << endl;
PrintTheRateOfReturnOfTheStock();
double TheRateOfReturnOfTheStock = TheRateOfReturnOfTheStock_();
PrintOutputTheRateOfReturnOfTheStock(TheRateOfReturnOfTheStock);
system("pause");
}

void PrintPercentageOfControllingOwners(void){
cout << "          ____________________________________________________________________" << endl;
cout << "         |                     Percentage Of Controlling Owners               |" << endl;
cout << "         |____________________________________________________________________|" << endl;
}

double PercentageOfControllingOwners_(void){
double FinalNetIncome = ReadNumber("    Final net income: ");
float Tax = Tax_("    Percentage Of Controlling Owners: %");
return FinalNetIncome * Tax;
}

void PrintOutPutPercentageOfControllingOwners(double PercentageOfControllingOwners){
cout << "    ============================================" << endl;
cout << "    Percentage Of Controlling Owners: " << PercentageOfControllingOwners << Coin << endl;
cout << "    ============================================" << endl;
}

void Percentage_Of_Controlling_Owners(void){
system("cls");
PrintMultiStageIncomeStatement();
cout << endl;
PrintPercentageOfControllingOwners();
double PercentageOfControllingOwners = PercentageOfControllingOwners_();
PrintOutPutPercentageOfControllingOwners(PercentageOfControllingOwners);
system("pause");
}

void PrintPercentageOfNonControllingOwners(void){
cout << "    ____________________________________________" << endl;
cout << "    Percentage Of Non-Controlling Owners: " << endl;
cout << "    ____________________________________________" << endl;
}

double PercentageOfNonControllingOwners_(void){
double FinalNetIncome = ReadNumber("    Final net income: ");
float Tax = Tax_("Percentage Of Controlling Owners: %");
float ReverseTax = ReverseTax_(Tax);
return FinalNetIncome * ReverseTax;

}

void PrintOutPutPercentageOfNonControllingOwners(double PercentageOfNonControllingOwners){
cout << "    ============================================" << endl;
cout << "    Percentage Of Non-Controlling Owners: " << PercentageOfNonControllingOwners << Coin << endl;
cout << "    ============================================" << endl;

};

void Percentage_Of_Non_Controlling_Owners(void){
system("cls");
PrintMultiStageIncomeStatement();
cout << endl;
PrintPercentageOfNonControllingOwners();
double PercentageOfNonControllingOwners = PercentageOfNonControllingOwners_();
PrintOutPutPercentageOfNonControllingOwners(PercentageOfNonControllingOwners);
system("pause");
}

void PrintPreparingExcludedOperations(void){
cout << "    ____________________________________________" << endl;
cout << "    Preparing excluded operations: " << endl;
cout << "    ____________________________________________" << endl;

}

void PrintNetIncomefromContinuingoperationsAfterTaxAndBeforeTheDecision(double NetIncomeAndBeforeTheDecision){
cout << "    _________________________________________________________________________________" << endl;
cout << "    Net Income from Continuing operations After Tax And Before The Decision: " << NetIncomeAndBeforeTheDecision << Coin << endl;
cout << "    _________________________________________________________________________________" << endl;

}

double FilteringBeforeTheDecision_(double Tax){
double SumFiltering = 0;
do{
if(!YOrN("    Is there any other loss or damage before disposa? Y/N: ")){break;};
double Filtering = Filtering_(Tax);
SumFiltering += Filtering;
if(Filtering == 0){break;}
}while(true);

return SumFiltering;
}

double FilteringAfterTheDecision_(double Tax){
double SumFiltering = 0;
do{
if(!YOrN("    Is there any other loss or damage After disposa? Y/N: ")){break;};
double Filtering = Filtering_(Tax);
SumFiltering += Filtering;
if(Filtering == 0){break;}
}while(true);

return SumFiltering;
}

void Preparing_Excluded_Operations(void){
system("cls");

PrintMultiStageIncomeStatement();

cout << endl;

PrintPreparingExcludedOperations();

double NetIncomefromContinuingoperationsBeforeTax = ReadNumber("    Net Income from Continuing operations Before Tax: ");

float Tax = Tax_("    Tax rate: %");

double NetIncomefromContinuingoperationsAfterTax = Net_Income_from_Continuingoperations_After_Tax(NetIncomefromContinuingoperationsBeforeTax, Tax);

double FilteringAndBeforeTheDecision = FilteringBeforeTheDecision_(Tax);

double NetIncomeAndBeforeTheDecision = NetIncome_(NetIncomefromContinuingoperationsAfterTax, FilteringAndBeforeTheDecision);

PrintNetIncomefromContinuingoperationsAfterTaxAndBeforeTheDecision(NetIncomeAndBeforeTheDecision);

PrintExcludedOperations();

double FilteringAfterTheDecision = FilteringAfterTheDecision_(Tax);

double NetIncomeAfterTheDecision = NetIncome_(NetIncomeAndBeforeTheDecision, FilteringAfterTheDecision);

PrintNetIncome(NetIncomeAfterTheDecision);

system("pause");

}

void PrintStatementOfComprehensiveIncome(void){
cout << "          ====================================================================" << endl;
cout << "         |                  Statement of comprehensive income                 |" << endl;
cout << "          ====================================================================" << endl;

}

double PossessionOfAnUnrealizedInvestment_(float Tax){
bool Flag = TOrF("    Gain or loss on holding unrealized investments? Gain = 1, Loss = 0: ");
double PossessionOfAnUnrealizedInvestment = ReadNumber("    The value of an unrealized investment holding? ");
float ReverseTax = ReverseTax_(Tax);
PossessionOfAnUnrealizedInvestment *= ReverseTax;
if(!Flag){PossessionOfAnUnrealizedInvestment *= -1;}

return PossessionOfAnUnrealizedInvestment;
}

double TranslationOfForeignCurrencies_(float Tax){
bool Flag = TOrF("    Gain or loss from foreign currency translation? Gain = 1, Loss = 0: ");
double TranslationOfForeignCurrencies = ReadNumber("    The value of foreign currency translation? ");
float ReverseTax = ReverseTax_(Tax);
TranslationOfForeignCurrencies *= ReverseTax;
if(!Flag){TranslationOfForeignCurrencies *= -1;}

return TranslationOfForeignCurrencies;
}

double ActuarialForTheInsuranceAndPensionsFund_(float Tax){
bool Flag = TOrF("    Actuarial gain or loss for the insurance and pension fund? Gain = 1, Loss = 0: ");
double ActuarialForTheInsuranceAndPensionsFund = ReadNumber("    The actuarial value of the insurance and pension fund? ");
float ReverseTax = ReverseTax_(Tax);
ActuarialForTheInsuranceAndPensionsFund *= ReverseTax;
if(!Flag){ActuarialForTheInsuranceAndPensionsFund *= -1;}

return ActuarialForTheInsuranceAndPensionsFund;
}

double StatementOfComprehensiveIncome_(double NetIncome, double PossessionOfAnUnrealizedInvestment, double TranslationOfForeignCurrencies, double ActuarialForTheInsuranceAndPensionsFund){
return NetIncome + PossessionOfAnUnrealizedInvestment + TranslationOfForeignCurrencies + ActuarialForTheInsuranceAndPensionsFund;
}

void PrintStatementOfComprehensiveIncome(double StatementOfComprehensiveIncome){
cout << "    ============================================" << endl;
cout << "    Statement of comprehensive income: " << StatementOfComprehensiveIncome << Coin << endl;
cout << "    ============================================" << endl;
}

void Statement_Of_Comprehensive_Income(void){
system("cls");
PrintStatementOfComprehensiveIncome();
double NetIncome = ReadNumber("    Net Income: ");

float Tax = Tax_("    Tax rate: %");
double PossessionOfAnUnrealizedInvestment = PossessionOfAnUnrealizedInvestment_(Tax);
double TranslationOfForeignCurrencies = TranslationOfForeignCurrencies_(Tax);
double ActuarialForTheInsuranceAndPensionsFund = ActuarialForTheInsuranceAndPensionsFund_(Tax);
double StatementOfComprehensiveIncome = StatementOfComprehensiveIncome_(NetIncome, PossessionOfAnUnrealizedInvestment, TranslationOfForeignCurrencies, ActuarialForTheInsuranceAndPensionsFund);

PrintStatementOfComprehensiveIncome(StatementOfComprehensiveIncome);
system("pause");
}


void TopicIncomeStatement(void){
do{
system("cls");
PrintMainChooseModeIncomeStatement();

short ChooseMode = ReadNumber("    Choose Mode: ", 1, 8);

if(ChooseMode == enChooseModeIncomeStatement::MultiStageIncomeStatemectSimple){
Mult_iStage_Income_Statement_Simple();}

if(ChooseMode == enChooseModeIncomeStatement::MultiStageIncomeStatemectMorethananunknown){
Mult_iStage_Income_Statement_More_than_an_un_known();}

if(ChooseMode == enChooseModeIncomeStatement::TheRateOfReturnOfTheStock){
The_Rate_Of_Return_Of_The_Stock();}

if(ChooseMode == enChooseModeIncomeStatement::PercentageOfControllingOwners){
Percentage_Of_Controlling_Owners();}

if(ChooseMode == enChooseModeIncomeStatement::PercentageOfNonControllingOwners){
Percentage_Of_Non_Controlling_Owners();}

if(ChooseMode == enChooseModeIncomeStatement::PreparingExcludedOperations){
Preparing_Excluded_Operations();}

if(ChooseMode == enChooseModeIncomeStatement::StatementOfComprehensiveIncome){
Statement_Of_Comprehensive_Income();
}

if(ChooseMode == enChooseModeIncomeStatement::GoBack){break;}
}while(true);

ChooseTopic();

}

void PrintChooseTopic(void){
cout << "    ==========================================================" << endl;
cout << "    Choose a Topic" << endl;
cout << "    ==========================================================" << endl;
cout << "    [1] Income statement." << endl;
cout << "    [2] Statement of retained earnings." << endl;
cout << "    [3] Balance Sheet." << endl;
cout << "    [4] Go Back, Choose Coin." << endl;
cout << "    ==========================================================" << endl;

}

void PrintTopicStatementOfRetainedEarnings(void){
cout << "          ====================================================================" << endl;
cout << "         |                   Statement of retained earnings                   |" << endl;
cout << "          ====================================================================" << endl;
}

double CorrectionOfRevenueErrors_(float Tax){
double CorrectionOfRevenueErrors = 0;
do{
bool Flag = TOrF("    Decrease or increase in error in revenues? Decrease = 1, increase = 0: ");
double Count = ReadNumber("    Error value in revenue? ");
if(Count == 0){break;}
float ReverseTax = ReverseTax_(Tax);
Count *= ReverseTax;
if(!Flag){Count *= -1;}
Count *= -1;
CorrectionOfRevenueErrors += Count;
if(!YOrN("    Are there a pit in another revenue? Y/N: ")){break;}
}while(true);
return CorrectionOfRevenueErrors;
}

double ErrorCorrectionExpenses_(float Tax){
double ErrorCorrectionExpenses = 0;
do{
bool Flag = TOrF("    Decrease or increase in error in expense? Decrease = 1, increase = 0: ");
double Count = ReadNumber("    Error value in expense? ");
if(Count == 0){break;}
float ReverseTax = ReverseTax_(Tax);
Count *= ReverseTax;
if(!Flag){Count *= -1;}
ErrorCorrectionExpenses += Count;
if(!YOrN("    Are there a pit in another expenses? Y/N: ")){break;}
}while(true);

return ErrorCorrectionExpenses;
}

double TheDifferenceBetweenTheSystems_(void){
cout << "    The difference between systems over the years!?" << endl;
double NewSystem = ReadNumber("    New system: ");
double OldSystem = ReadNumber("    Old system: ");
return NewSystem - OldSystem;
}

double ErrorCorrectionIsTheCumulativeEffectsOfDifferencesAccountingMethods_(float Tax){
double BetweenCreditAndDebit = 0;
double TheDifferenceBetweenTheSystems = 0;
if(!YOrN("    Is There a difference from different ways? Y/N: ")){return 0;}

do{
short ChooseNumber = ReadNumber("    [1] Differences between credit and debit\n    [2] System differences\n    ", 1, 2);

if(ChooseNumber == enChooseCumulativeEffectsOfDifferencesAccountingMethods::DifferencesBetweenCreditAndDebit){
bool Flag = TOrF("    Differences between credit and debit? Creditor = 1, Debtor = 0: ");
double Count = ReadNumber("    The amount of change: ");
float ReverseTax = ReverseTax_(Tax);
Count *= ReverseTax;
if(!Flag){Count *= -1;}
BetweenCreditAndDebit += Count;
}

if(ChooseNumber == enChooseCumulativeEffectsOfDifferencesAccountingMethods::SystemDifferences){
do{
TheDifferenceBetweenTheSystems += TheDifferenceBetweenTheSystems_();
if(YOrN("    Is there a difference between the systems across another year? Y/N: ")){break;}
}while(true);
float ReverseTax = ReverseTax_(Tax);
TheDifferenceBetweenTheSystems *= ReverseTax;
}

if(!YOrN("    Is There any other error resulting from different ways? Y/N: ")){break;}
}while(true);
return BetweenCreditAndDebit + TheDifferenceBetweenTheSystems;
}

void PrintTheBalanceOfRetainedEarningsAtTheBeginningOfTheYear(void){
cout << "    ___________________________________________________________________" << endl;
cout << "    The balance of retained earnings at the beginning of the year" << endl;
cout << "    ___________________________________________________________________" << endl;

}

double AdjustedRetainedEarningsBalance_(double  BalanceOfRetainedOrGeneralEarnings, double Revenues, double Expenses, double CumulativeEffectsOfDifferencesAccountingMethods){
return BalanceOfRetainedOrGeneralEarnings + Revenues + Expenses + CumulativeEffectsOfDifferencesAccountingMethods;
}

void PrintAdjustedRetainedEarningsBalance(long long AdjustedRetainedEarningsBalance){
cout << "    __________________________________________" << endl;
cout << "    Adjusted retained earnings balance: " << AdjustedRetainedEarningsBalance << Coin << endl;
cout << "    __________________________________________" << endl;
}

double TheRetainedEarningsBalanceAtTheEndOfTheYear_(double AdjustedRetainedEarningsBalance, double NetIncome, double Distributions){
return AdjustedRetainedEarningsBalance + NetIncome - Distributions;
}

void PrintTheRetainedEarningsBalanceAtTheEndOfTheYear(long long TheRetainedEarningsBalanceAtTheEndOfTheYear){
cout << "    _______________________________________________________________" << endl;
cout << "    The retained earnings balance at the end of the year: " << TheRetainedEarningsBalanceAtTheEndOfTheYear << Coin << endl;
cout << "    _______________________________________________________________" << endl;
}

void TopicStatementOfRetainedEarnings(void){
system("cls");

PrintTopicStatementOfRetainedEarnings();

PrintTheBalanceOfRetainedEarningsAtTheBeginningOfTheYear();
double Tax = Tax_("    Tax rate: %");
double BalanceOfRetainedOrGeneralEarnings = ReadNumber("    Balance of retained or general earnings: ");
double CorrectionOfRevenueErrors = CorrectionOfRevenueErrors_(Tax);
double ErrorCorrectionExpenses = ErrorCorrectionExpenses_(Tax);
double CumulativeEffectsOfDifferencesAccountingMethods = ErrorCorrectionIsTheCumulativeEffectsOfDifferencesAccountingMethods_(Tax);
double AdjustedRetainedEarningsBalance = AdjustedRetainedEarningsBalance_(BalanceOfRetainedOrGeneralEarnings, CorrectionOfRevenueErrors, ErrorCorrectionExpenses, CumulativeEffectsOfDifferencesAccountingMethods); 

PrintAdjustedRetainedEarningsBalance(AdjustedRetainedEarningsBalance);

double NetIncome = ReadNumber("    Net income: ");
double Distributions = ReadNumber("    Distributions: ");
double TheRetainedEarningsBalanceAtTheEndOfTheYear = TheRetainedEarningsBalanceAtTheEndOfTheYear_(AdjustedRetainedEarningsBalance, NetIncome, Distributions);
PrintTheRetainedEarningsBalanceAtTheEndOfTheYear(TheRetainedEarningsBalanceAtTheEndOfTheYear);
system("pause");
}

void PrintChooseStageInBalanceSheet(void){
cout << "    ==========================================================" << endl;
cout << "    Choose Stage In Balance Sheet" << endl;
cout << "    ==========================================================" << endl;
cout << "    [1] Current Asstes." << endl;
cout << "    [2] Non_Current Asstes." << endl;
cout << "    [3] Liabilities." << endl;
cout << "    [4] Owner Is Equity." << endl;
cout << "    [5] Go Back." << endl;
cout << "    ==========================================================" << endl;

}

double Invectory_(void){
cout << "    Invectory:_" << endl;
double InvectoryAtCost = ReadNumber("    Invectory At Cost: ");
double InvectoryMarketValue = ReadNumber("    Invectory Market Value: ");
if(InvectoryAtCost < InvectoryMarketValue){return InvectoryAtCost;}
return InvectoryMarketValue;
}

double GoodDebt_(double Client){
double CustomDebtIsQuestionable = ReadNumber("    Custom Debt Is Questionable: ");
return Client - CustomDebtIsQuestionable;
}

double CurrentValueOfNotesReceivable_(double NotesReceivable){
double CustomNotesReceivable = ReadNumber("    CustomNotesReceivable: ");
return NotesReceivable - CustomNotesReceivable;
}

void PrintCurrentAsstes(void){
cout << "    ======================================" << endl;
cout << "    Current Asstes" << endl;
cout << "    ======================================" << endl;
}

double TotalCurrentAsstes_(double CashBank, double OfficeSupplies, double InvestmentTermShort, double PrepaidExpensesAndAccruedRevenue, double Invectory, double GoodDebt, double CurrentValueOfNotesReceivable){
return CashBank + OfficeSupplies + InvestmentTermShort + PrepaidExpensesAndAccruedRevenue + Invectory + GoodDebt + CurrentValueOfNotesReceivable;
}

void printTotalCurrentAsstes(double TotalCurrentAsstes){
cout << "    ______________________________________" << endl;
cout << "    Total Current Asstes: " << TotalCurrentAsstes << Coin << endl;
cout << "    ______________________________________" << endl;

}

void Current_Asstes(void){
system("cls");
PrintCurrentAsstes();

double CashBank = ReadNumber("    Cash / Bank: ");
double OfficeSupplies = ReadNumber("    Office Supplies: ");
double InvestmentTermShort = ReadNumber("    Investment Term Short: ");
double PrepaidExpensesAndAccruedRevenue = ReadNumber("    Prepaid Expenses And Accrued Revenue: ");
double Invectory = Invectory_();
double Client = ReadNumber("    Client: "); //
double GoodDebt = GoodDebt_(Client);
double NotesReceivable = ReadNumber("    Notes Receivable: "); //
double CurrentValueOfNotesReceivable = CurrentValueOfNotesReceivable_(NotesReceivable);

double TotalCurrentAsstes = TotalCurrentAsstes_(CashBank, OfficeSupplies, InvestmentTermShort, PrepaidExpensesAndAccruedRevenue, Invectory, GoodDebt, CurrentValueOfNotesReceivable);
printTotalCurrentAsstes(TotalCurrentAsstes);

system("pause");
}

void PrintNonCurrentAsstes(void){
cout << "    ======================================" << endl;
cout << "    Non_Current Asstes" << endl;
cout << "    ======================================" << endl;
}

double DirtyValues_(double FixedAssets){
double EroticCompound = ReadNumber("    The Erotic Compound: ");
return FixedAssets - EroticCompound;
}

double TotalNonCurrentAsstes_(double InvestmentTermLong, double DirtyValues, double NetNonTangibleAssets, double OtherAssets){
return InvestmentTermLong + DirtyValues + NetNonTangibleAssets + OtherAssets;
}

void printTotalNonCurrentAsstes(double TotalNonCurrentAsstes){
cout << "    ______________________________________" << endl;
cout << "    Total Non_Current Asstes: " << TotalNonCurrentAsstes << Coin << endl;
cout << "    ______________________________________" << endl;
}

double NetNonTangibleAssets_(double NonTangibleAssets){
double ExplanationExpenses = ReadNumber("    Explanation Expenses: ");
return NonTangibleAssets - ExplanationExpenses;
}

void Non_Current_Asstes(void){
system("cls");
PrintNonCurrentAsstes();

double InvestmentTermLong = ReadNumber("    Investment Term Long: ");
double FixedAssets = ReadNumber("    Fixed Assets (Land, Building, Equipent, Machines, Furniture Car/Truks): "); //
double DirtyValues = DirtyValues_(FixedAssets);
double NonTangibleAssets = ReadNumber("    Non_Tangible Assets (The Fame, Trade Mark, Branding): "); //
double NetNonTangibleAssets = NetNonTangibleAssets_(NonTangibleAssets);
double OtherAssets = ReadNumber("    Other Assets (Cash For Expansions, Prepaid Expenses And Accrued Revenue Term Long, Defrred Tax Assets): ");

double TotalNonCurrentAsstes = TotalNonCurrentAsstes_(InvestmentTermLong, DirtyValues, NetNonTangibleAssets, OtherAssets);
printTotalNonCurrentAsstes(TotalNonCurrentAsstes);

system("pause");
}

void PrintLiabilities(void){
cout << "    =============================" << endl;
cout << "    Liabilities" << endl;
cout << "    =============================" << endl;
}

double TotalCrrentLiabilities_(double Suppliers, double AccountPayable, double NotesPayable, double ShortTermLand, double AccruedExpenses, double UnearnedRevenue){
return Suppliers, AccountPayable + NotesPayable + ShortTermLand + AccruedExpenses + UnearnedRevenue;
}

void printTotalCrrentLiabilities(double TotalCrrentLiabilities){
cout << "    _____________________________" << endl;
cout << "    Total Crrent Liabilities: " << TotalCrrentLiabilities << Coin << endl;
cout << "    _____________________________" << endl;
}

double TotalLongTermLiabilities_(double LongTremSuppliers, double LongTremAccountPayable, double LongTremNotesPayable, double LongTremLand, double LongTremAccruedExpenses, double LongTremUnearnedRevenue){
return LongTremSuppliers + LongTremAccountPayable + LongTremNotesPayable + LongTremLand + LongTremAccruedExpenses + LongTremUnearnedRevenue;
}

void PrintTotalLongTermLiabilities(double TotalLongTermLiabilities){
cout << "    _____________________________" << endl;
cout << "    Total Long Term Liabilities: " << TotalLongTermLiabilities << Coin << endl;
cout << "    _____________________________" << endl;
}

void Crrent_Liabilities_And_Long_Term_Liabilities(void){
system("cls");
PrintLiabilities();
cout << "    Crrent Liabilities:_" << endl;
double Suppliers = ReadNumber("    Suppliers: ");
double AccountPayable = ReadNumber("    Account Payable: ");
double NotesPayable = ReadNumber("    Notes Payable: "); 
double ShortTermLand = ReadNumber("    Short Term Land: ");
double AccruedExpenses = ReadNumber("    Accrued Expenses: ");
double UnearnedRevenue = ReadNumber("    Unearned Revenue: ");

double TotalCrrentLiabilities = TotalCrrentLiabilities_(Suppliers, AccountPayable, NotesPayable, ShortTermLand, AccruedExpenses, UnearnedRevenue);
printTotalCrrentLiabilities(TotalCrrentLiabilities);

cout << "    Long Term Liabilities:_" << endl;
double LongTremSuppliers = ReadNumber("    Long Trem Suppliers: ");
double LongTremAccountPayable = ReadNumber("    Long Trem Account Payable: ");
double LongTremNotesPayable = ReadNumber("    Long Trem Notes Payable: "); 
double LongTremLand = ReadNumber("    Long Trem Land: ");
double LongTremAccruedExpenses = ReadNumber("    Long Trem Accrued Expenses: ");
double LongTremUnearnedRevenue = ReadNumber("    Long Trem Unearned Revenue: ");

double TotalLongTermLiabilities = TotalLongTermLiabilities_(LongTremSuppliers, LongTremAccountPayable, LongTremNotesPayable, LongTremLand, LongTremAccruedExpenses, LongTremUnearnedRevenue);
PrintTotalLongTermLiabilities(TotalLongTermLiabilities);

system("pause");
}

double Capital_(void){
if(YOrN("    Do You Know Capital? Y/N: ")){
return ReadNumber("    The capital value: ");
}

double NumberOfShares = ReadNumber("    Number Of Shares: ");
double NominalValue = ReadNumber("    Nominal Value: ");
return NumberOfShares * NominalValue;
}

double BonusBalances_(void){
if(YOrN("    Do You Know Bonus Balances? Y/N: ")){
return ReadNumber("    The Bonus Balances value: ");
}

double NumberOfShares = ReadNumber("    Number Of Shares: ");
double PriceDifference = ReadNumber("    The Price Difference: ");
return NumberOfShares * PriceDifference;
}

void PrintOwnerIsEquity(void){
cout << "    =================================" << endl;
cout << "    Owner Is Equity" << endl;
cout << "    =================================" << endl;
}

double TotalOwnerIsEquity_(double Capital, double BonusBalances, double Precautios, double RetainedEarnings, double TreasuryShares){
return Capital + BonusBalances + Precautios + RetainedEarnings - TreasuryShares;
}

void printTotalOwnerIsEquity(double TotalOwnerIsEquity){
cout << "    _________________________________" << endl;
cout << "    Total Owner Is Equity: " << TotalOwnerIsEquity << Coin << endl;
cout << "    _________________________________" << endl;
}

void Owner_Is_Equity(void){
system("cls");
PrintOwnerIsEquity();
double Capital = Capital_();
double BonusBalances = BonusBalances_();
double Precautios = ReadNumber("    Precautios: ");
double RetainedEarnings = ReadNumber("    Retained Earnings: ");
double TreasuryShares = ReadNumber("    Treasury Shares: ");

double TotalOwnerIsEquity = TotalOwnerIsEquity_(Capital, BonusBalances, Precautios, RetainedEarnings, TreasuryShares);
printTotalOwnerIsEquity(TotalOwnerIsEquity);

system("pause");
}

void TopicBalanceSheet(void){
do{
system("cls");
PrintChooseStageInBalanceSheet();

int ChooseStageInBalanceSheet = ReadNumber("    Choose Stage In Balance Sheet: ", 1, 5);

if(ChooseStageInBalanceSheet == enChooseStageInBalanceSheet::CurrentAsstes){
Current_Asstes();
}

if(ChooseStageInBalanceSheet == enChooseStageInBalanceSheet::NonCurrentAsstes){
Non_Current_Asstes();
}

if(ChooseStageInBalanceSheet == enChooseStageInBalanceSheet::Liabilities){
Crrent_Liabilities_And_Long_Term_Liabilities();
}

if(ChooseStageInBalanceSheet == enChooseStageInBalanceSheet::OwnerIsEquity){
Owner_Is_Equity();
}


if(ChooseStageInBalanceSheet == enChooseStageInBalanceSheet::GoBAck){break;}

}while(true);

ChooseTopic();
}

void ChooseTopic(void){
do{
system("cls");
PrintChooseTopic();

short ChooseTopic = ReadNumber("    Choose Mode: ", 1, 4);

if(ChooseTopic == enChooseTopic::IncomeStatement){
TopicIncomeStatement();}

if(ChooseTopic == enChooseTopic::StatementOfRetainedEarnings){
TopicStatementOfRetainedEarnings();}

if(ChooseTopic == enChooseTopic::BalanceSheet){
TopicBalanceSheet();}

if(ChooseTopic == enChooseTopic::GoBackChooseCoin){break;}
}while(true);

ChooseCoinAndTopic();

}

void PrintChooseCoin(void){
cout << "    ==========================================================" << endl;
cout << "    Choose a Coin" << endl;
cout << "    ==========================================================" << endl;
cout << "    [1] Dollar." << endl;
cout << "    [2] Egyptian pound." << endl;
cout << "    [3] Euro." << endl;
cout << "    [4] Sterling." << endl;
cout << "    [5] Saudi Riyal." << endl;
cout << "    [6] Exit." << endl;
cout << "    ==========================================================" << endl;

}

bool ChooseCoin(void){
system("cls");
PrintChooseCoin();
short ChooseCoin = ReadNumber("    Choose Coin: ", 1, 6);
if(ChooseCoin == enChooseCoin::Dollar){Coin = "$";}
if(ChooseCoin == enChooseCoin::EgyptianPound){Coin = "EGP";}
if(ChooseCoin == enChooseCoin::Euro){Coin = "€";}
if(ChooseCoin == enChooseCoin::Sterling){Coin = "GBP";}
if(ChooseCoin == enChooseCoin::SaudiRiyal){Coin = "SAR";}
if(ChooseCoin == enChooseCoin::Exit){return 1;}
return 0;
}

bool ChooseCoinAndTopic(void){
system("cls");
if(ChooseCoin()){exit(0);}
ChooseTopic();
}

void IntermediateAccounting(void){
PrintIntermediateAccounting();

cout << endl;

system("pause");

ChooseCoinAndTopic();

}

int main(void){
IntermediateAccounting();

return 0;
}


// Mohamed Essam