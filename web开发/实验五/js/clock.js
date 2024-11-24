// 创建一个包含完整时间信息的 data 对象
const data = {
  year: 0,
  month: 0,
  day: 0,
  weekday: '',
  hours: 0,
  minutes: 0,
  seconds: 0,
  milliseconds: 0,
  timeZoneOffset: '',  // 新增字段，保存时区偏移信息
  updateTime: function() {
    const now = new Date(); // 获取当前时间
    this.year = now.getFullYear();
    this.month = now.getMonth() + 1; // 月份从 0 开始，需要加 1
    this.day = now.getDate();
    this.weekday = ['星期天', '星期一', '星期二', '星期三', '星期四', '星期五', '星期六'][now.getDay()]; // 获取星期
    this.hours = now.getHours();
    this.minutes = now.getMinutes();
    this.seconds = now.getSeconds();
    this.milliseconds = now.getMilliseconds(); // 获取毫秒

    // 获取时区偏移量（单位为分钟），并将其转换为类似 "UTC+8" 的格式
    const offset = now.getTimezoneOffset();  // 获取时区偏移（相对于 UTC，单位为分钟）
    const sign = offset > 0 ? "-" : "+";  // 根据偏移量判断时区符号
    const hours = Math.floor(Math.abs(offset) / 60);  // 获取时区的小时部分
    const minutes = Math.abs(offset) % 60;  // 获取时区的分钟部分

    this.timeZoneOffset = `UTC${sign}${hours < 10 ? '0' + hours : hours}:${minutes < 10 ? '0' + minutes : minutes}`;
  },
  formatTime: function() {
    // 格式化时间为完整的时间字符串，精确到毫秒并包含时区
    let timeString = `${this.year}年${this.month < 10 ? '0' + this.month : this.month}月${this.day < 10 ? '0' + this.day : this.day}日 ` +
           `${this.weekday} ` +
           `${this.hours < 10 ? '0' + this.hours : this.hours}:${this.minutes < 10 ? '0' + this.minutes : this.minutes}:${this.seconds < 10 ? '0' + this.seconds : this.seconds}.${this.milliseconds < 100 ? '0' + (this.milliseconds < 10 ? '0' + this.milliseconds : this.milliseconds) : this.milliseconds} ` +
           `时区: ${this.timeZoneOffset}`;

    // 如果分钟数为50，输出“还差十秒一分钟”
    if (this.seconds === 50) {
      timeString += "\n还差十秒一分钟！";
    }

    return timeString;
  }
};

// 每毫秒更新一次时间并显示
function updateClock() {
  data.updateTime(); // 更新时间
  document.getElementById('clock').textContent = data.formatTime(); // 更新时钟显示
}

// 初次加载时更新一次时钟
updateClock();
// 每毫秒更新时钟
setInterval(updateClock, 1); // 以毫秒为单位更新
