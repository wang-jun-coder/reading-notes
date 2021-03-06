# 大话设计模式

## 创建型模式
* **抽象工厂模式**： 提供一个创建一系列或相关依赖对象的接口，而无需指定它们具体的类  
![abstract-factory.png](15-abstract-factory/abstract-factory.png)
* **建造者模式**： 将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示  
![builder.png](13-builder/builder.png)
* **工厂方法模式**： 定义一个用于创建对象的接口，让子类决定实例化哪一个类， 工厂模式使一个类的实例化延迟到其子类  
![factory.png](08-factory/factory.png)
* **原型模式**： 用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象  
![prototype.png](09-prototype/prototype.png)
* **单例模式**：保证一个类仅有一个实例，并提供一个访问它的全局访问点  
![singleton.png](21-singleton/singleton.png)

## 结构型模式
* **适配器模式**：将一个类的接口转换成客户希望的另外一个接口，适配器模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作  
![adapter.png](17-adapter/adapter.png)
* **桥接模式**：将抽象部分与其实现部分分离，使他们都可以独立的变化    
![bridge.png](22-bridge/bridge.png)
* **组合模式**：将对象组合成树形结构以表示 `部分·整体`的层次结构，组合模式使得用户对单个对象和组合对象的使用具有一致性  
![composite.png](19-composite/composite.png)
* **装饰模式**：动态的给一个对象添加一些额外的职责，就增加功能来说，装饰模式比生成子类更加灵活  
![decorator.png](06-decorator/decorator.png)
* **外观模式**：为子系统中的一组接口提供一个一致的界面，外观模式定义了一个高层接口，这个接口使得这一子系统更加容易使用  
![facade.png](12-facade/facade.png)
* **享元模式**：运用共享技术有效的支持大量细粒度的对象  
![flyweight.png](26-flyweight/flyweight.png)
* **代理模式**：为其他对象提供一种代理以控制对这个对象的访问  
![proxy.png](07-proxy/proxy.png)

## 行为型模式
* **观察者模式**：定义对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新  
![observer.png](14-observer/observer.png)
* **模板方法模式**：定义一个操作的算法骨架，而将一些步骤延迟到子类中，模板方法使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤    
![template.png](10-templete/template.png)
* **命令模式**：将一个请求封装为一个对象，从而使你可以用不同的请求对客户进行参数化，可以对请求排队或记录请求日志，以及支持可撤销的操作  
![command.png](23-command/command.png)
* **状态模式**：允许一个对象在其内部状态改变时改变它的行为，让对象看起来似乎修改了它的类  
![state.png](16-state/state.png)
* **职责链模式**：使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合。将这些对象连成一条链，并沿着这条链传递该请求，直到有一个对象处理它为止。  
![chain-of-responsibility.png](24-chain-of-responsibility/chain-of-responsibility.png)
* **解释器模式**：给定一个语言，定义它的文法的一种表示，并定义一个解释器，这个解释器使用该表示来解释语言中的句子。  
![interpreter.png](27-interpreter/interpreter.png)
* **中介者模式**：用一个中介对象来封装一系列的对象交互。中介者使各对象不需显式的相互引用，从而使其耦合松散，而且可以独立地改变它们之间的交互  
![mediator.png](25-mediator/mediator.png)
* **访问者模式**：一个作用于某对象结构中的各元素的操作，它使你可以在不改变各元素的类的前提下定义作用于这些元素的新操作。  
![visitor.png](28-visitor/visitor.png)
* **策略模式**：定义一系列算法，把它们一个个封装起来，并且使它们可以相互替换。本模式使得算法可以独立于使用它的客户而变化  
![strategy.png](02-strategy/strategy.png)
* **备忘录模式**：在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态，这样以后就可以将该对象恢复到原先保存的状态  
![memento.png](18-memento/memento.png)
* **迭代器模式**：提供一种方法顺序访问一个聚合对象中各个元素，而又不需要暴露该对象的内部表示  
![iterator.png](20-iterator/iterator.png)
