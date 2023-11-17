package pckg;

public class TelephoneOperator {

    private  Integer ID;
    private Integer callerNumber;
    private Integer calledNumber;
    private String date;
    private String time;
    private Integer duration;
    private Integer costOneTariffUnit;
    private Integer billingUnit;
    private Integer costCall;

    public TelephoneOperator(){

    }

    public TelephoneOperator(Integer callerNumber, Integer calledNumber, String date, String time, Integer duration, Integer costOneTariffUnit, Integer billingUnit){
        this.callerNumber = callerNumber;
        this.calledNumber = calledNumber;
        this.date = date;
        this.time = time;
        this.duration = duration;
        this.costOneTariffUnit = costOneTariffUnit;
        this.billingUnit = billingUnit;
        this.costCall = calculateCost(duration, costOneTariffUnit, billingUnit);
    }

    public Integer calculateCost(Integer duration, Integer costOneTariffUnit, Integer billingUnit){
        Integer resultDuration = billingUnit;
        if (duration % billingUnit != 0){
            return this.costCall = (duration / billingUnit) * costOneTariffUnit;
        }
        else if (duration < billingUnit)
            return costOneTariffUnit;
        else {
            while (resultDuration < duration) {
                resultDuration += billingUnit;
            }
            return this.costCall = ((resultDuration)/ billingUnit) * costOneTariffUnit;
        }
    }

    public Integer getID() {
        return ID;
    }

    public Integer getCallerNumber(){
        return  callerNumber;
    }

    public Integer getBillingUnit() {
        return billingUnit;
    }

    public Integer getCalledNumber() {
        return calledNumber;
    }

    public Integer getCostCall() {
        return costCall;
    }

    public Integer getCostOneTariffUnit() {
        return costOneTariffUnit;
    }

    public Integer getDuration() {
        return duration;
    }

    public String getDate() {
        return date;
    }

    public String getTime() {
        return time;
    }

    public void setBillingUnit(Integer billingUnit) {
        this.billingUnit = billingUnit;
    }

    public void setCalledNumber(Integer calledNumber) {
        this.calledNumber = calledNumber;
    }

    public void setCallerNumber(Integer callerNumber) {
        this.callerNumber = callerNumber;
    }

    public void setCostCall(Integer costCall) {
        this.costCall = costCall;
    }

    public void setCostOneTariffUnit(Integer costOneTariffUnit) {
        this.costOneTariffUnit = costOneTariffUnit;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public void setDuration(Integer duration) {
        this.duration = duration;
    }

    public void setTime(String time) {
        this.time = time;
    }

    public void setID(Integer ID){
        this.ID = ID;
    }
}
