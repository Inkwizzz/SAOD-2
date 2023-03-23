Test();

void Test()
{
    using (Person j = new Person("John"))
    {
        Console.WriteLine($"Name: {j.Name}");
    }
    Console.WriteLine("Конец метода Test");
}
public class Person : IDisposable
{
    public string Name { get; }
    public Person(string name) => Name = name;

    public void Dispose() => Console.WriteLine($"{Name} удалён");
}