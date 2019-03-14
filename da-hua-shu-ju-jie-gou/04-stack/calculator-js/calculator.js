/**
 * 计算四则运算表达式(中缀表达式)
 * @param expression
 */
function calculator(expression) {
    const rpn = transferExpressionToRPN(expression);
    return calculatorWithRPN(rpn);
}

/**
 * 获取运算符优先级
 *
 * @param op 运算符, 暂时支持 + - * / ( )
 * @return {number} 运算符优先级, 如运算符不存在, 则返回-1
 */
function getPriorityOfOperation(op) {

    const priority = {
        '+':1,
        '-':1,
        '*':2,
        '/':2,
        '(':3,
        ')':3
    };
    return priority[op] || -1;
}

/**
 * 转换中缀表达式为后缀表达式
 *
 * @param expression 中缀表达式
 * @return {string} 后缀表达式
 */
function transferExpressionToRPN(expression) {

    // 前置数据处理
    expression = expression.replace(/\+/g, ' + ');
    expression = expression.replace(/-/g, ' - ');
    expression = expression.replace(/\*/g, ' * ');
    expression = expression.replace(/\//g, ' / ');
    expression = expression.replace(/\(/g, ' ( ');
    expression = expression.replace(/\)/g, ' ) ');
    expression = expression.replace(/\s+/g, ',');
    const array = expression.split(',');
    console.log(array);

    let rpn = '';
    let stack = [];

    array.forEach(item => {

        const num = parseFloat(item);

        // 数字
        if (!isNaN(num)) {
            rpn += ` ${num}`;
            return;
        }

        // 空栈或者为(. 则直接入栈
        if (stack.length === 0 || '(' === item) {
            stack.push(item);
            return;
        }

        // 如果是右括号, 则出栈, 直接匹配到左括号
        if (')' === item) {

            let top = stack[stack.length-1];
            // 没遇到匹配的左括号, 循环
            while ('(' !== top || !stack.length) {
                top = stack.pop();
                if (top !== '(') {
                    rpn += ` ${top}`;
                }
            }
            return;
        }

        // 如果顶部是 ( 则直接入栈
        let top = stack[stack.length-1];
        if('(' === top) {
            stack.push(item);
            return;
        }

        // 普通则对比当前操作符和栈顶操作符优先级, 当前高则入栈, 否则出栈
        let pTop = getPriorityOfOperation(top);
        const pCur = getPriorityOfOperation(item);
        if (pCur > pTop) {
            stack.push(item);
            return;
        }

        // 当前操作符优先级低, 出栈, 然后将当前操作符入栈
        while (pTop >= pCur  && stack.length) {
            top = stack.pop();
            rpn += ` ${top}`;
            pTop = getPriorityOfOperation(top);
        }
        stack.push(item);
    });

    // 将栈中符号全部取出
    while (stack.length) {
        rpn += ` ${stack.pop()}`;
    }

    return rpn.substr(1,rpn.length-1);
}

/**
 * 计算后缀表达式的值
 *
 * @param rpn 后缀表达式
 * @return {number} 计算结果
 */
function calculatorWithRPN(rpn) {
    const stack = [];
    const array = rpn.split(' ');

    array.forEach(item => {
        const num = Number(item);

        // 数字
        if (!isNaN(num)) {
            stack.push(num);
            return;
        }

        const numB = stack.pop();
        const numA = stack.pop();
        if ('+' === item) {
            stack.push(numA+numB);
        }
        if ('-' === item) {
            stack.push(numA-numB);
        }
        if ('*' === item) {
            stack.push(numA*numB);
        }
        if ('/' === item) {
            stack.push(numA/numB);
        }
    });


    return stack.pop();
}


/*
* 测试代码
* */
function test() {
    const exp = '9.5+(5-1)*3+10/2';
    const  res = calculator(exp);
    console.log(`${exp} = ${res}`);
}
test();

