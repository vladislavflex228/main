using System;
using System.Collections.Generic;
using System.ComponentModel;


namespace Classes
{
    
    class Deposit
    {
        private static double DepSum{get ; set ; }

        public Deposit(double depSum)
        {
            DepSum = depSum;
        }

        public override string ToString()
        {
            return $"{DepSum}$";
        }

        public static void changeDepPlus(double diff)
        {
            DepSum += diff;
        }
        public static void changeDepMinus(double diff)
        {
            DepSum -= diff;
        }

        public static double GetDep()
        {
            return DepSum;
        }
    }

    class Bank
    {
        private string BankName{get ; set; }
        private int DepCount{get ; set; }
        private double Bet{get ; set; }

        public List<Deposit> Deps;

        private static readonly Lazy<Bank> bank = new Lazy<Bank>(() => new Bank());

        private static bool is_initialized = false;
        

        private static readonly object _lock = new object();            //static здесь играет ключевую роль,ведь "ключ" для всех объектов класса должен быть один

        public static Bank Instance
        {
            get {return bank.Value ;}
        }

        private Bank()
        {
            Console.WriteLine(">>>Инициализация банка и суммы депозитов<<<");
            BankName = " ";
            Deps = new List<Deposit>();

        }

        public void Initialize(string bankName,int depCount,double bet,double depSum)        //не может быть статик,ведь мы должны обращаться к конкретным свойствам класса
        {
            lock (_lock)
            {
                if (is_initialized)
                {
                    throw new InvalidOperationException("Банк уже инициализирован");
                }
                else
                {
                    BankName = bankName;
                    Bet = bet;
                    is_initialized = true;
                    for(int i = 0;i < depCount; i++)
                    {
                        this.Add(depSum);
                    }
                }
            }
        }
        public void ResetData()
        {
            lock (_lock)
            {
                BankName = "Пустое имя";
                DepCount = 0;
                DepCount = 0;
                is_initialized = false;
                Deps = new List<Deposit>();
            }
        }

        public double SumOfDeps(double depSum)
        {
            double sum = Bet * DepCount * depSum / 100d;

            return sum;
        }

        public void ChangeDepPlus(double diff)
        {
            
            Deposit.changeDepPlus(diff);
            
        }
        public void ChangeDepMinus(double diff)
        {
            
            Deposit.changeDepMinus(diff);
        }

        public string FullInf()
        {
            return $" \"{BankName}\" - Сумма Вклада: {Deposit.GetDep()}, Процентная ставка: {Bet} , Количество вкладов: {DepCount}";
        }


        public void Add(double depSum)
        {
            Deps.Add(new Deposit(depSum));
            DepCount++;
        }

        public double GetDepSum()
        {
            return Deposit.GetDep();
        }

        
    }
}