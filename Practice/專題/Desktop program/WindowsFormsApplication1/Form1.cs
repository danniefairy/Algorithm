using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.IO;
namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Process LOL = new Process();
            LOL.StartInfo.FileName = "C:\\Program Files\\Garena Plus\\GarenaMessenger.exe";
            LOL.Start();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Process Youtube = new Process();
            Youtube.StartInfo.FileName = "explorer.exe";
            Youtube.StartInfo.Arguments = "https://www.youtube.com/";
            Youtube.Start();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Process Youtube = new Process();
            Youtube.StartInfo.FileName = "explorer.exe";
            Youtube.StartInfo.Arguments = "https://www.facebook.com/";
            Youtube.Start();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            label1.Text =  DateTime.Now.ToLongDateString() + DateTime.Now.ToLongTimeString();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            System.IO.File.Delete(@"Login.txt");
            FileStream fs = new FileStream(@"Login.txt", FileMode.OpenOrCreate);
            StreamWriter sw = new StreamWriter(fs);
            sw.Write(this.textBox1.Text);
            sw.Close();
            fs.Close();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
        }

        private void button6_Click(object sender, EventArgs e)
        {
            string line;
            StreamReader sr = new StreamReader(@"Login.txt", Encoding.Default);

            for (int i = 1; i <= 100; i++)
            {
                line = sr.ReadLine();
                if (line != null)
                    textBox1.Text = textBox1.Text + line.ToString() + Environment.NewLine;
            }
            textBox1.SelectionStart = textBox1.Text.Length;
            textBox1.ScrollToCaret();
            sr.Close();
        }

      

     

     
    }
}
