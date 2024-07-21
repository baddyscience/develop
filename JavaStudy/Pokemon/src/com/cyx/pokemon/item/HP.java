package com.cyx.pokemon.item;

/**
 * 药品：回复血量
 */
public class HP extends Item{

    private int count;

    public HP(int levelNumber, int count) {
        super("天山雪莲", levelNumber);
        this.count = count;
    }

    /**
     * 使用药品可以回复血量
     * @return
     */
    public int use(){
        count--;
        return levelNumber * 500;
    }

    public int getCount() {
        return count;
    }

    /**
     * 堆叠药品
     * @param count
     */
    public void addCount(int count){
        this.count += count;
    }

    /**
     * 检测药品是否可以被销毁
     * @return
     */
    public boolean canDestroy(){
        return count == 0;
    }

    @Override
    public String getItemInformation() {
        return name;
    }
}
