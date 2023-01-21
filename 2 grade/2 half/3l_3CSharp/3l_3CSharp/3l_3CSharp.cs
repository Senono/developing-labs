using System;

namespace _3l_3CSharp
{
    class Warrior
    {
        private int hp;
        private double coef { get; set; }
        public int Hp
        {
            get => hp;
            set
            {
                if (hp > -1 && hp < 101) hp = value;
            }
        }

        public Warrior(double c = 1, int h = 100)
        {
            coef = c;
            Hp = h;
        }
        
        public void dmg(int h)
        {
            Hp = hp -  (int)(h * coef);
        }
    }

    class LightWarrior:Warrior
    {
        public LightWarrior(double c = 0.8) : base(c) { }
        public int Hpp
        {
            get => base.Hp;
        }
    }

    class HeavyWarrior:Warrior
    {
        public HeavyWarrior(double c = 0.5):base(c) { }
        public int Hpp
        {
            get => base.Hp;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Warrior warrior = new Warrior();
            LightWarrior lightWarrior = new LightWarrior();
            HeavyWarrior heavyWarrior = new HeavyWarrior();

            Console.WriteLine("Здоровье воина: " + warrior.Hp);
            warrior.dmg(5);
            Console.WriteLine("Здоровте после получение 5 урона: " + warrior.Hp);
            warrior.dmg(5);
            Console.WriteLine("Здоровте после получение 5 урона: " + warrior.Hp);
            warrior.dmg(5);
            Console.WriteLine("Здоровте после получение 5 урона: " + warrior.Hp);

            Console.WriteLine("Здоровье воина в легкой броне: " + lightWarrior.Hp);
            lightWarrior.dmg(5);
            Console.WriteLine("Здоровте после получение 5 урона: " + lightWarrior.Hp);
            lightWarrior.dmg(5);
            Console.WriteLine("Здоровте после получение 5 урона: " + lightWarrior.Hp);
            lightWarrior.dmg(5);
            Console.WriteLine("Здоровте после получение 5 урона: " + lightWarrior.Hp);

            Console.WriteLine("Здоровье воина в тяжелой броне: " + heavyWarrior.Hp);
            heavyWarrior.dmg(5);
            Console.WriteLine("Здоровте после получение 5 урона: " + heavyWarrior.Hp);
            heavyWarrior.dmg(5);
            Console.WriteLine("Здоровте после получение 5 урона: " + heavyWarrior.Hp);
            heavyWarrior.dmg(5);
            Console.WriteLine("Здоровте после получение 5 урона: " + heavyWarrior.Hp);


        }
    }
}
