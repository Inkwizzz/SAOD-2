using System;
using System.Text.RegularExpressions;
using System.IO;
using System.Xml;


namespace RegExpLab
{
    class Program
    {
        static void Main(string[] args)
        {
            string orig;
            try
            {
                using (StreamReader sr = new StreamReader("Dictionary.xml"))
                {
                    orig = sr.ReadToEnd();
                    Console.WriteLine(orig.Length);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка чтения файла: \"Dictionary.xml\"\n{0}", ex);
                return;
            }

            //string str = " фыиsдо, fjbld33- 2олт?";
            //Console.WriteLine(str);
            //Regex re = new Regex(@".");
            //Regex re = new Regex(@"\w+");
            //Regex re = new Regex(@"\b[0-9]+\w+\b");
            //Regex re = new Regex(@"\w*\d\w*");
            //Regex re = new Regex(@"\w+3\b");
            //Regex re = new Regex(@"(\w)\1");
            //Regex re = new Regex(@"\b\w*(\w)\1\w*\b");
            //Regex re = new Regex(@"(\W*)(\w+)(\W+)(\w+)(\W+)(\w+)(\W*)");
            //Console.WriteLine(re.Replace(str, "$1$4$3$2$5$6$7"));
            //Regex re = new Regex(@"\b[A-Za-z0-9]+\b");
            //Regex re = new Regex(@"\b\w*[a-zA-Z]\w*\b");
            //MatchCollection mc = re.Matches(str);
            //foreach (var m in mc)
            //    Console.WriteLine(m);
            Regex re = new Regex(@"<(\w+)[^<>]*>([^<>]+)<\/\1>");
            var mc = re.Matches(orig);
            foreach (var m in mc)
                Console.WriteLine(m.ToString());

            Console.Read();
        }
    }
}
