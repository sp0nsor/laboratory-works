import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class Storage {
    private static Map<Integer, TelephoneOperator> calls = new HashMap<Integer, TelephoneOperator>();
    static {
        TelephoneOperator call;
        call = new TelephoneOperator(12345, 54321, "16.10.2023", "00:55", 90, 2, 15);
        create(call);

        call = new TelephoneOperator(5678, 8765, "16.10.2023", "1:23", 30, 2, 15);
        create(call);

        call = new TelephoneOperator(8901, 1098, "16.10.2023", "1.:30", 60, 2, 15);
        create(call);
    }

    public static  Collection <TelephoneOperator> readAll(){
        return calls.values();
    }

    public  static  TelephoneOperator readById (Integer id){
        return calls.get(id);
    }

    public static void update (TelephoneOperator call){
        calls.put(call.getID(), call);
    }

    public static void delete (Integer id){
        calls.remove(id);
    }
    public static void create (TelephoneOperator call){
        Integer id = 1;
        Set<Integer> ids = calls.keySet();
        if (!ids.isEmpty()){
            id += Collections.max(ids);
        }

        call.setID(id);
        calls.put(id, call);
    }
}
