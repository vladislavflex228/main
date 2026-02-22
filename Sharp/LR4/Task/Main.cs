using System;
using System.Threading.Tasks.Dataflow;
using Classes;

class Task
{
    public static void Main()
    {
        Console.WriteLine("Лабу номер 4 выполнил Антонюк Владислав группа 553501,5 вариант");       //Короче надо Reset добавить и все

        var bank1 = Bank.Instance;

        bool start = true;

        while (start)
        {
            Console.WriteLine("Меню программы: ");
            Console.WriteLine("Начать инициализацию - 1");
            Console.WriteLine("Выйти из выполнения программы - 2");

            string programm = Console.ReadLine()!;

            switch (programm)
            {
                case "1":
                    {
                        
                        Console.Write("Введите название банка: ");
                        string bankName = Console.ReadLine()!;
                        Console.WriteLine();

                        int depCount;
                        double bet;
                        double depSum;

                        while (true)
                        {
                            Console.Write("Введите количество вкладов: ");
                            string DepCount = Console.ReadLine()!;
                            Console.WriteLine();
                            
                            bool trueCount = int.TryParse(DepCount,out depCount) && depCount > 0;

                            if (!trueCount)
                            {
                                Console.WriteLine("Некорректный ввод количества влкадов");
                                continue;
                            }
                            break;
                        }
                        
                        while (true)
                        {
                            Console.Write("Введите процентную ставку в процентах: ");
                            string Bet = Console.ReadLine()!;
                            Console.WriteLine();

                            bool trueBet = double.TryParse(Bet,out bet) && bet >=0 && bet <= 100;

                            if (!trueBet)
                            {
                                Console.WriteLine("Некорректный ввод процента ставок");
                                continue;
                            }
                            break;
                        }
                        while (true)
                        {
                            Console.Write("Введите сумму вклада: ");
                            string DepSum = Console.ReadLine()!;
                            Console.WriteLine();

                            bool trueSum = double.TryParse(DepSum,out depSum) && depSum > 0;
                            if (!trueSum)
                            {
                                Console.WriteLine("Некорректный ввод суммы вклада");
                                continue;
                            }
                            break;
                        }

                        bank1.Initialize(bankName,depCount,bet,depSum);

                        var bank2 = Bank.Instance;

                        bool equal_banks = ReferenceEquals(bank1,bank2);

                        if (equal_banks)
                        {
                            Console.WriteLine("Ссылки на банки совпадают");
                        }

                        bool setts = true;

                        while (setts)
                        {
                            Console.WriteLine("Меню Настроек: ");
                            Console.WriteLine("Уменьшить сумму вклада на пол величину - 1");
                            Console.WriteLine("Увеличить сумму вклада - 2");
                            Console.WriteLine("Получить общую сумму выплат по процентам - 3");
                            Console.WriteLine("Добавить вклад - 4");
                            Console.WriteLine("Получить полную информацию о банке - 5");
                            Console.WriteLine("Завершить настройку - 6");
                            string _set = Console.ReadLine()!;
                            switch (_set)
                            {
                                case "1":
                                    {
                                        bool correct_input = false;
                                        while (!correct_input)
                                        {
                                            double diff;
                                    
                                            string Diff = Console.ReadLine()!;

                                            if(double.TryParse(Diff,out diff) && diff <= depSum && diff >= 0)
                                            {
                                                bank1.ChangeDepMinus(diff);
                                                correct_input = true;
                                            }
                                            else
                                            {
                                                Console.WriteLine("Некорректный ввод");
                                            }
                                        }
                                        
                                        break;
                                    }
                                case "2":
                                    {
                                        bool correct_input = false;
                                        while (!correct_input)
                                        {
                                            double diff;
                                    
                                            string Diff = Console.ReadLine()!;

                                            if(double.TryParse(Diff,out diff) && diff >= 0)
                                            {
                                                bank1.ChangeDepPlus(diff);
                                                correct_input = true;

                                            }
                                            else
                                            {
                                                Console.WriteLine("Некорректный ввод");
                                            }
                                        }
                                        
                                        break;
                                    }
                                case "3":
                                    {
                                        Console.WriteLine($"Общая сумма выплат по проценту равна: {bank1.SumOfDeps(bank1.GetDepSum())}");
                                        break;
                                    }
                                case "4":
                                    {
                                        bank1.Add(depSum);
                                        break;
                                    }
                                case "5":
                                    {
                                        Console.WriteLine(bank1.FullInf());
                                        break;
                                    }
                                case "6":
                                    {
                                        Console.WriteLine("Настройки завершены");
                                        setts = false;
                                        break;
                                    }
                                default:
                                    {
                                        Console.WriteLine("Некорректный ввод случая,попробуйте еще раз");
                                        break;
                                    }
                                
                            }
                        }
                        bank1.ResetData();
                        break;
                    }
                case "2":
                    {
                        start = false;
                        break;
                    }
                default:
                    {
                        Console.WriteLine("Некорректный ввод");
                        break;
                    }
            }

            
        }

        
    }
}