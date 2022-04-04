#### C# winform

* anchor属性保证控件随窗体大小变化而变化，每个控件都要设置

* 现有一PictureBox控件，十多个Label以及Button，那么只将这些Label和Button放入Panel中。同时在Form_Load事件中加入如下代码即可实现背景透明：
    this.picturebox1.SendToBack();//将背景图片放到最下面
    this.panel1.BackColor = Color.Transparent;//将Panel设为透明
    this.panel1.Parent = this.picturebox1;//将panel父控件设为背景图片控件
    this.panel1.BringToFront();//将panel放在前面

  以上代码即可实现所有的控件都对PictueBox背景图片透明。

* 控件如何去掉框后者改变框的颜色border

* 更改字体颜色

  `label1.Font = new Font("微软雅黑", 10, FontStyle.Bold); //第一个是字体，第二个大小，第三个是样式，
              tx_username.Font = new Font("微软雅黑",10,FontStyle.Bold);
              tx_username.ForeColor = Color.Red;
              label1.ForeColor = Color.Blue;`