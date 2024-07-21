package com.cyx.pokemon.level;

/**
 * 关卡
 */
public class Level {
    /**
     * 关卡编号
     */
    private int number;
    /**
     * 关卡地图
     */
    private LevelMap map;

    private Level prevLevel;

    private Level nextLevel;

    public Level(Level prevLevel, int number, Level nextLevel) {
        this.number = number;
        this.prevLevel = prevLevel;
        this.nextLevel = nextLevel;
        this.map = new LevelMap(number);
    }

    public int getNumber() {
        return number;
    }

    public LevelMap getMap() {
        return map;
    }

    public Level getPrevLevel() {
        return prevLevel;
    }

    public void setPrevLevel(Level prevLevel) {
        this.prevLevel = prevLevel;
    }

    public Level getNextLevel() {
        return nextLevel;
    }

    public void setNextLevel(Level nextLevel) {
        this.nextLevel = nextLevel;
    }
}
