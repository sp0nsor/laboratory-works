public class Main {
    public static void main(String[] args){
        String _str = "J!a!v!a!";
        int _size = _str.length();
        StringBuffer stringBuffer = new StringBuffer(_str);
        for (int i = 0; i < _str.length(); i++){
            if (_str.charAt(i)== '!'){
                _size++;
            }
        }
        System.out.println(ChangeStringCharacther(stringBuffer, _size));
    }
    public static StringBuffer ChangeStringCharacther(StringBuffer stringBuffer, int _size){
        int cnt = 1;
        for (int i = 0; i < _size; i++){
            if (stringBuffer.charAt(i) == '!'){
                stringBuffer.insert(i+1,cnt);
                cnt++;
            }
        }
        return stringBuffer;
    }
}