public class TelephoneOperator {

    private  int ID;
    private int callerNumber;
    private int calledNumber;
    private String date;
    private String time;
    private int duration;
    private int costOneTariffUnit;
    private int billingUnit;
    private int costCall;

    public TelephoneOperator(int callerNumber, int calledNumber, String date, String time, int duration, int costOneTariffUnit, int billingUnit){
        this.callerNumber = callerNumber;
        this.calledNumber = calledNumber;
        this.date = date;
        this.time = time;
        this.duration = duration;
        this.costOneTariffUnit = costOneTariffUnit;
        this.billingUnit = billingUnit;
        this.costCall = calculateCost(duration, costOneTariffUnit, billingUnit);
    }

    private int calculateCost(int duration, int costOneTariffUnit, int billingUnit){
        int resultDuration = billingUnit;
        if (duration % billingUnit != 0){
            while (resultDuration < duration){
                resultDuration += billingUnit;
            }
        }

        return this.costCall = (resultDuration / billingUnit) * costOneTariffUnit;
    }

    public int getID() {
        return ID;
    }

    public int getCallerNumber(){
        return  callerNumber;
    }

    public int getBillingUnit() {
        return billingUnit;
    }

    public int getCalledNumber() {
        return calledNumber;
    }

    public int getCostCall() {
        return costCall;
    }

    public int getCostOneTariffUnit() {
        return costOneTariffUnit;
    }

    public int getDuration() {
        return duration;
    }

    public String getDate() {
        return date;
    }

    public String getTime() {
        return time;
    }

    public void setBillingUnit(int billingUnit) {
        this.billingUnit = billingUnit;
    }

    public void setCalledNumber(int calledNumber) {
        this.calledNumber = calledNumber;
    }

    public void setCallerNumber(int callerNumber) {
        this.callerNumber = callerNumber;
    }

    public void setCostCall(int costCall) {
        this.costCall = costCall;
    }

    public void setCostOneTariffUnit(int costOneTariffUnit) {
        this.costOneTariffUnit = costOneTariffUnit;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public void setDuration(int duration) {
        this.duration = duration;
    }

    public void setTime(String time) {
        this.time = time;
    }

    public void setID(int ID){
        this.ID = ID;
    }
}
