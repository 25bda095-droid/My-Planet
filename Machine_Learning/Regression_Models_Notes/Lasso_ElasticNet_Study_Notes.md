# 📘 Lasso & Elastic Net Regression — Complete Study Notes

> **Compiled from:** `lasso-regression-demo.ipynb`, `lasso-regression-key-points.ipynb`, and `Lasso+ElasticNet_annotated.pdf`

---

## Table of Contents

1. [Recap: OLS & The Overfitting Problem](#1-recap-ols--the-overfitting-problem)
2. [What is Regularization?](#2-what-is-regularization)
3. [Ridge vs Lasso — L2 vs L1 Norms](#3-ridge-vs-lasso--l2-vs-l1-norms)
4. [Lasso Regression (L1 Regularization)](#4-lasso-regression-l1-regularization)
5. [Mathematical Derivation of Lasso](#5-mathematical-derivation-of-lasso)
6. [Why Lasso Creates Sparsity (Very Important!)](#6-why-lasso-creates-sparsity-very-important)
7. [How Alpha (λ) Affects Coefficients](#7-how-alpha-λ-affects-coefficients)
8. [Impact on Bias and Variance](#8-impact-on-bias-and-variance)
9. [Lasso — Code Implementation (sklearn)](#9-lasso--code-implementation-sklearn)
10. [Elastic Net Regression](#10-elastic-net-regression)
11. [Ridge vs Lasso vs Elastic Net — Quick Comparison](#11-ridge-vs-lasso-vs-elastic-net--quick-comparison)
12. [Important Questions for Revision](#12-important-questions-for-revision)
13. [Quick Revision Cheat Sheet](#13-quick-revision-cheat-sheet)

---

## 1. Recap: OLS & The Overfitting Problem

### Simple Linear Regression (1 feature)

$$\hat{y} = mx + b$$

where:
- $m$ = slope (coefficient)
- $b$ = intercept = $\bar{y} - m\bar{x}$

The slope in simple linear regression is found by:

$$m = \frac{\sum_{i=1}^{n}(y_i - \bar{y})(x_i - \bar{x})}{\sum_{i=1}^{n}(x_i - \bar{x})^2}$$

### The Overfitting Problem

| Concept | Description |
|---------|-------------|
| **Underfitting** | Model is too simple (high bias, low variance). Example: fitting a straight line to quadratic data. |
| **Good fit** | Model captures the true pattern without memorizing noise. |
| **Overfitting** | Model is too complex (low bias, high variance). Example: fitting a high-degree polynomial to simple data. |

> **Key Insight:** When you increase polynomial degree → complexity ↑ → overfitting risk ↑

**Regularization** is the technique used to **prevent overfitting** by adding a penalty term to the loss function.

---

## 2. What is Regularization?

Regularization adds a **penalty** to the loss function to discourage large coefficient values.

$$\mathcal{L}_{\text{regularized}} = \text{Loss}(\text{data}) + \lambda \cdot \text{Penalty}(\text{coefficients})$$

where:
- $\lambda$ (alpha) controls the **strength** of the penalty
- Higher $\lambda$ → more penalty → simpler model → higher bias, lower variance
- Lower $\lambda$ → less penalty → complex model → lower bias, higher variance

> **If $\lambda = 0$:** regularized regression becomes normal linear regression.

---

## 3. Ridge vs Lasso — L2 vs L1 Norms

### L2 Norm (Ridge Regression)

$$\|w\|_2^2 = w_1^2 + w_2^2 + w_3^2 + \cdots + w_n^2$$

Ridge loss function:

$$\mathcal{L}_{\text{Ridge}} = \sum_{i=1}^{n}(y_i - \hat{y}_i)^2 + \lambda \|w\|_2^2 = \text{MSE} + \lambda(w_1^2 + w_2^2 + \cdots + w_n^2)$$

### L1 Norm (Lasso Regression)

$$\|w\|_1 = |w_1| + |w_2| + |w_3| + \cdots + |w_n|$$

Lasso loss function:

$$\mathcal{L}_{\text{Lasso}} = \sum_{i=1}^{n}(y_i - \hat{y}_i)^2 + \lambda \|w\|_1 = \text{MSE} + \lambda(|w_1| + |w_2| + \cdots + |w_n|)$$

### Key Difference at a Glance

| Property | Ridge (L2) | Lasso (L1) |
|----------|-----------|-----------|
| Penalty term | $\lambda \sum w_j^2$ | $\lambda \sum \|w_j\|$ |
| Coefficients → 0? | **Tends toward 0** but never exactly 0 | **Can be exactly 0** |
| Feature selection? | ❌ No | ✅ Yes |
| Best when | Many small/medium features contribute | Few features are truly important |

---

## 4. Lasso Regression (L1 Regularization)

### Definition

**LASSO** = **L**east **A**bsolute **S**hrinkage and **S**election **O**perator

### Loss Function

$$\boxed{\mathcal{L}_{\text{Lasso}} = \text{MSE} + \lambda \|w\|_1 = \sum_{i=1}^{n}(y_i - \hat{y}_i)^2 + \lambda \sum_{j=1}^{p} |w_j|}$$

### Three Super-Powers of Lasso

1. **Shrinks coefficients** — reduces overfitting
2. **Drives coefficients to exactly zero** — automatic **feature selection**
3. **Reduces dimensionality** — fewer non-zero features = simpler model

> **Remember:** Higher coefficients are shrunk more aggressively by Lasso!

---

## 5. Mathematical Derivation of Lasso

### Starting Point (Simple LR with 1 feature)

$$\hat{y} = mx + b, \quad b = \bar{y} - m\bar{x}$$

The Lasso loss function for simple linear regression:

$$\mathcal{L} = \sum_{i=1}^{n}(y_i - \hat{y}_i)^2 + \lambda |m|$$

### Taking the Derivative

$$\frac{d\mathcal{L}}{dm} = \sum_{i=1}^{n} (y_i - mx_i - \bar{y} + m\bar{x}) \cdot (-x_i + \bar{x}) + \lambda \cdot \text{sign}(m) \cdot 1$$

> **Note:** The derivative of $|m|$ depends on the sign of $m$:
> - If $m > 0$: $\frac{d|m|}{dm} = +1$
> - If $m < 0$: $\frac{d|m|}{dm} = -1$
> - If $m = 0$: undefined (sub-gradient = 0)

### Setting $\frac{d\mathcal{L}}{dm} = 0$ and solving:

After simplification:

$$-\sum\left[(y_i - \bar{y}) - m(x_i - \bar{x})\right](x_i - \bar{x}) + \lambda \cdot \text{sign}(m) = 0$$

$$-\sum(y_i - \bar{y})(x_i - \bar{x}) + m\sum(x_i - \bar{x})^2 + \lambda \cdot \text{sign}(m) = 0$$

### Final Formula — Three Cases

$$\boxed{m = \begin{cases} \dfrac{\sum(y_i - \bar{y})(x_i - \bar{x}) - \lambda}{\sum(x_i - \bar{x})^2} & \text{if } m > 0 \\[12pt] \dfrac{\sum(y_i - \bar{y})(x_i - \bar{x})}{\sum(x_i - \bar{x})^2} & \text{if } m = 0 \\[12pt] \dfrac{\sum(y_i - \bar{y})(x_i - \bar{x}) + \lambda}{\sum(x_i - \bar{x})^2} & \text{if } m < 0 \end{cases}}$$

> **Compare with Ridge Regression:**
> $$m_{\text{Ridge}} = \frac{\sum(y_i - \bar{y})(x_i - \bar{x})}{\sum(x_i - \bar{x})^2 + \lambda}$$
> In Ridge, $\lambda$ appears in the **denominator** → $m$ tends to 0 but **never reaches** 0.

---

## 6. Why Lasso Creates Sparsity (Very Important!)

This is one of the **most important** concepts to understand!

### The Key Insight

| Regression | Where does $\lambda$ appear? | Can $m = 0$? |
|------------|------------------------------|-------------|
| **Ridge** | In the **denominator**: $\sum(x_i-\bar{x})^2 + \lambda$ | **No** — denominator just grows, $m$ → 0 but never = 0 |
| **Lasso** | In the **numerator**: $\sum(y_i-\bar{y})(x_i-\bar{x}) - \lambda$ | **Yes!** — if $\lambda$ ≥ numerator, $m$ becomes 0 |

### Numerical Example (from the PDF)

Consider: $\sum Y \cdot X = 100$, $\sum X^2 = 50$

| $\lambda$ | $m$ (Lasso, $m>0$ case) | Status |
|---|---|---|
| 0 | $\frac{100-0}{50} = 2$ | Same as OLS |
| 10 | $\frac{100-10}{50} = 1.8$ | Shrunk |
| 50 | $\frac{100-50}{50} = 1$ | Shrunk more |
| 100 | $\frac{100-100}{50} = 0$ | **Exactly zero!** |
| > 100 | Use $m<0$ formula → still small | Near zero |

> **When** $\lambda = 100$**, the numerator becomes 0, so** $m = 0$**.**
> This is **why Lasso creates sparsity** — it can zero out coefficients completely!

### But wait — what about the $m < 0$ case?

If numerator $100 - \lambda < 0$ (e.g., $\lambda = 150$), then $m$ would be negative from the $m > 0$ formula. **Contradiction!** So the formula **switches** to the $m < 0$ case:

$$m = \frac{100 + 150}{50} = 5$$

This is also a contradiction (positive from negative formula). So **$m$ must be 0**.

> **Summary:** When $\lambda$ is large enough, the numerator becomes 0 → coefficient is exactly 0 → **feature is eliminated!**

---

## 7. How Alpha (λ) Affects Coefficients

### Observed on the Diabetes Dataset (10 features)

| Alpha ($\lambda$) | Effect |
|---|---|
| 0 | Same as OLS — all 10 coefficients are non-zero |
| 0.1 | Some small coefficients shrink to 0 (e.g., `age`, `s2`, `s4`) |
| 1.0 | Most coefficients = 0; only `bmi` and `s5` survive |
| 10 | **All coefficients = 0** — model predicts the mean |

### Key Observations

1. **Higher coefficients are affected more** by the penalty
2. **As $\lambda$ increases:**
   - More coefficients → 0
   - R² score generally decreases
   - Model becomes simpler (higher bias, lower variance)
3. The coefficient paths show how each feature "survives" different $\lambda$ values

> **Think of it like a survival game:** As $\lambda$ increases, features get eliminated one by one. The last ones standing are the most important!

---

## 8. Impact on Bias and Variance

### The Bias-Variance Tradeoff in Lasso

$$\text{Total Error} = \text{Bias}^2 + \text{Variance} + \text{Irreducible Error}$$

| $\lambda$ | Overfitting | Bias | Variance |
|---|---|---|---|
| **Small** (→ 0) | ↑ More overfitting | ↓ Low bias | ↑ High variance |
| **Large** (→ ∞) | ↓ Less overfitting | ↑ High bias | ↓ Low variance |

### How to Choose $\lambda$?

> **We choose $\lambda$ at the sweet spot** where total error (bias² + variance) is minimized.
> - This region is where the bias-variance curves cross.
> - In practice, use **cross-validation** (e.g., `LassoCV` in sklearn).

### Visualizing the Tradeoff

```
Error
  ↑
  |    ╲  Variance          / Bias²
  |     ╲                  /
  |      ╲               /
  |       ╲    Total    /
  |        ╲  Error   /
  |         ╲___●___/    ← Choose λ here!
  |              
  └──────────────────────────→ λ (alpha)
       small            large
```

---

## 9. Lasso — Code Implementation (sklearn)

### Basic Lasso

```python
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import Lasso
from sklearn.datasets import make_regression, load_diabetes
from sklearn.model_selection import train_test_split
from sklearn.metrics import r2_score

# Generate data
X, y = make_regression(n_samples=100, n_features=1, 
                       n_informative=1, noise=20, random_state=13)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

# Fit Lasso with different alphas
alphas = [0, 1, 5, 10, 30]
for alpha in alphas:
    lasso = Lasso(alpha=alpha)
    lasso.fit(X_train, y_train)
    y_pred = lasso.predict(X_test)
    print(f"Alpha={alpha}, R²={r2_score(y_test, y_pred):.4f}")
    print(f"  Coefficients: {lasso.coef_}")
```

### Viewing Coefficient Shrinkage

```python
from sklearn.datasets import load_diabetes

data = load_diabetes()
X_train, X_test, y_train, y_test = train_test_split(
    data.data, data.target, test_size=0.2, random_state=2
)

alphas = [0, 0.1, 1, 10]
for alpha in alphas:
    reg = Lasso(alpha=alpha)
    reg.fit(X_train, y_train)
    y_pred = reg.predict(X_test)
    print(f"\nAlpha = {alpha}, R² = {r2_score(y_test, y_pred):.2f}")
    for name, coef in zip(data.feature_names, reg.coef_):
        print(f"  {name}: {coef:.4f}")
```

### Coefficient Path Visualization

```python
alphas = [0, 0.0001, 0.0005, 0.001, 0.005, 0.1, 0.5, 1, 5, 10]
coefs = []

for alpha in alphas:
    reg = Lasso(alpha=alpha)
    reg.fit(X_train, y_train)
    coefs.append(reg.coef_.tolist())

# Plot
coef_array = np.array(coefs).T
plt.figure(figsize=(15, 8))
plt.plot(alphas, np.zeros(len(alphas)), color='black', linewidth=5)
for i in range(coef_array.shape[0]):
    plt.plot(alphas, coef_array[i], label=data.feature_names[i])
plt.xlabel('Alpha (λ)')
plt.ylabel('Coefficient Value')
plt.title('Lasso Coefficient Path')
plt.legend()
plt.show()
```

### Bias-Variance Decomposition

```python
from mlxtend.evaluate import bias_variance_decomp

# With PolynomialFeatures + Lasso
for alpha in [0, 0.001, 0.01, 0.1, 1, 10]:
    avg_loss, avg_bias, avg_var = bias_variance_decomp(
        Lasso(alpha=alpha), X_train, y_train.ravel(),
        X_test, y_test.ravel(),
        loss='mse', num_rounds=100, random_seed=123
    )
    print(f'Alpha={alpha}:  Loss={avg_loss:.4f}  '
          f'Bias²={avg_bias:.4f}  Variance={avg_var:.4f}')
```

---

## 10. Elastic Net Regression

### What is Elastic Net?

**Elastic Net = Ridge + Lasso** — it combines **both** L1 and L2 penalties!

### Loss Function

$$\boxed{\mathcal{L}_{\text{ElasticNet}} = \sum_{i=1}^{n}(y_i - \hat{y}_i)^2 + a\|w\|_2^2 + b\|w\|_1}$$

where:
- $a$ = weight of the **Ridge** (L2) component
- $b$ = weight of the **Lasso** (L1) component
- $\lambda = a + b$ (total regularization strength)

### The `l1_ratio` Parameter

In sklearn, the Elastic Net is parameterized using `l1_ratio`:

$$\text{l1\_ratio} = \frac{a}{a + b} = \frac{a}{\lambda}$$

So the formula becomes:

$$\mathcal{L} = \sum(y_i - \hat{y}_i)^2 + \lambda \left[\text{l1\_ratio} \cdot \|w\|_1 + (1 - \text{l1\_ratio}) \cdot \|w\|_2^2\right]$$

| `l1_ratio` | Behavior |
|---|---|
| **0** | Pure Ridge regression |
| **0.5** | Equal mix of Ridge and Lasso |
| **1** | Pure Lasso regression |

### When to Use Elastic Net?

> **Use Elastic Net when the input data has multicollinearity.**

- Adjust `l1_ratio` to balance the effect of Ridge vs Lasso
- If you want **feature selection** → increase `l1_ratio` (more Lasso)
- If you want **stability with correlated features** → decrease `l1_ratio` (more Ridge)

### Code

```python
from sklearn.linear_model import ElasticNet

elastic = ElasticNet(alpha=1.0, l1_ratio=0.5)
elastic.fit(X_train, y_train)
y_pred = elastic.predict(X_test)
print(f"R² = {r2_score(y_test, y_pred):.4f}")
print(f"Coefficients: {elastic.coef_}")
```

---

## 11. Ridge vs Lasso vs Elastic Net — Quick Comparison

| Feature | Ridge | Lasso | Elastic Net |
|---------|-------|-------|-------------|
| **Penalty** | $\lambda \sum w_j^2$ | $\lambda \sum \|w_j\|$ | $\lambda_1 \sum w_j^2 + \lambda_2 \sum \|w_j\|$ |
| **Norm** | L2 | L1 | L1 + L2 |
| **Coefficients → 0?** | ❌ Shrinks, never 0 | ✅ Can be exactly 0 | ✅ Can be exactly 0 |
| **Feature selection** | ❌ No | ✅ Yes | ✅ Yes |
| **Handles multicollinearity** | ✅ Yes | ⚠️ Picks one, drops rest | ✅ Yes |
| **Best for** | Many small features | Few important features | Multicollinear data |
| **Where λ appears** | Denominator | Numerator | Both |

---

## 12. Important Questions for Revision

### ❓ Q1: Why does Lasso create sparsity but Ridge does not?

**Answer:**
- In **Ridge**, $\lambda$ appears in the **denominator** of the slope formula:
  $m = \frac{\sum(y_i-\bar{y})(x_i-\bar{x})}{\sum(x_i-\bar{x})^2 + \lambda}$
  As $\lambda$ increases, the denominator grows → $m$ **approaches 0 but never reaches it**.

- In **Lasso**, $\lambda$ appears in the **numerator**:
  $m = \frac{\sum(y_i-\bar{y})(x_i-\bar{x}) - \lambda}{\sum(x_i-\bar{x})^2}$
  When $\lambda$ exceeds the numerator, $m$ becomes **exactly 0**. This is **sparsity**!

---

### ❓ Q2: What happens when α = 0 in Lasso?

**Answer:** Lasso becomes **normal linear regression** (OLS). There is no penalty, so all coefficients are unrestricted.

---

### ❓ Q3: How does Lasso perform feature selection?

**Answer:** As the regularization parameter $\lambda$ increases, Lasso progressively shrinks coefficients. The **less important** features (those with smaller contributions) are driven to **exactly zero first**. Only the most important features retain non-zero coefficients. This is automatic feature selection!

---

### ❓ Q4: What is the effect of increasing alpha on Bias and Variance?

**Answer:**
- **Increasing $\lambda$:** Overfitting ↓, Bias ↑, Variance ↓
- **Decreasing $\lambda$:** Overfitting ↑, Bias ↓, Variance ↑
- We choose $\lambda$ in the **region where total error is minimized** (the sweet spot).

---

### ❓ Q5: Why use Elastic Net instead of Lasso?

**Answer:** When features are **multicollinear** (highly correlated), Lasso tends to **arbitrarily pick one** and drop the rest. Elastic Net, by adding the Ridge (L2) penalty, handles groups of correlated features better — it tends to keep or drop them **together**.

---

### ❓ Q6: What is `l1_ratio` in ElasticNet?

**Answer:**
- `l1_ratio = a / (a + b)` where $a$ is the L2 weight and $b$ is the L1 weight.
- `l1_ratio = 0` → pure Ridge
- `l1_ratio = 1` → pure Lasso
- `l1_ratio = 0.5` → equal mix

---

### ❓ Q7: Higher coefficients are affected more by Lasso — why?

**Answer:** Since Lasso subtracts a **constant** $\lambda$ from the numerator, this constant has a **proportionally larger effect** on small numerators (small coefficients) than large ones. However, in absolute terms, all coefficients lose the same amount from the numerator. The smaller ones hit zero first, while larger ones survive longer. So effectively, small coefficients vanish first, and then progressively larger ones vanish too.

---

### ❓ Q8: Write the loss function for Ridge, Lasso, and Elastic Net.

**Answer:**

$$\mathcal{L}_{\text{Ridge}} = \sum_{i=1}^{n}(y_i - \hat{y}_i)^2 + \lambda \sum_{j=1}^{p} w_j^2$$

$$\mathcal{L}_{\text{Lasso}} = \sum_{i=1}^{n}(y_i - \hat{y}_i)^2 + \lambda \sum_{j=1}^{p} |w_j|$$

$$\mathcal{L}_{\text{ElasticNet}} = \sum_{i=1}^{n}(y_i - \hat{y}_i)^2 + \lambda\left[\alpha \sum_{j=1}^{p} |w_j| + (1-\alpha) \sum_{j=1}^{p} w_j^2\right]$$

---

## 13. Quick Revision Cheat Sheet

```
┌─────────────────────────────────────────────────────────────────┐
│                    LASSO REGRESSION CHEAT SHEET                 │
├─────────────────────────────────────────────────────────────────┤
│                                                                 │
│  LASSO = L1 Regularization                                     │
│  Loss = MSE + λ·|w₁| + λ·|w₂| + ... + λ·|wₙ|                 │
│                                                                 │
│  ★ Can make coefficients EXACTLY ZERO → Feature Selection       │
│  ★ λ in NUMERATOR of slope formula                              │
│  ★ Higher λ → more coefficients = 0 → simpler model            │
│  ★ λ = 0 → normal linear regression                            │
│                                                                 │
│  RIDGE = L2 Regularization                                      │
│  Loss = MSE + λ·w₁² + λ·w₂² + ... + λ·wₙ²                    │
│                                                                 │
│  ★ Coefficients SHRINK but NEVER = 0                            │
│  ★ λ in DENOMINATOR of slope formula                            │
│  ★ Good when all features matter                                │
│                                                                 │
│  ELASTIC NET = Ridge + Lasso = L1 + L2                          │
│  Loss = MSE + a·||w||² + b·||w||                                │
│  l1_ratio = a/(a+b)                                             │
│                                                                 │
│  ★ Use when data has MULTICOLLINEARITY                          │
│  ★ l1_ratio=0 → Ridge, l1_ratio=1 → Lasso                      │
│                                                                 │
│  BIAS-VARIANCE:                                                 │
│  λ ↑  →  Bias ↑, Variance ↓, Overfitting ↓                    │
│  λ ↓  →  Bias ↓, Variance ↑, Overfitting ↑                    │
│  Choose λ at the SWEET SPOT (use cross-validation)              │
│                                                                 │
│  WHY LASSO CREATES SPARSITY:                                    │
│  Lasso: m = [Σ(yi-ȳ)(xi-x̄) - λ] / Σ(xi-x̄)²                │
│  Ridge: m = Σ(yi-ȳ)(xi-x̄) / [Σ(xi-x̄)² + λ]                │
│  In Lasso, λ subtracts from numerator → can make it 0!         │
│  In Ridge, λ adds to denominator → numerator never 0!          │
│                                                                 │
└─────────────────────────────────────────────────────────────────┘
```

---

> **💡 Final Tip for Exams:**
> The #1 question they will ask is **"Why does Lasso create sparsity?"**
> Answer: Because $\lambda$ appears in the **numerator** (not denominator like Ridge), so when $\lambda$ is large enough, the numerator becomes 0, making the coefficient exactly 0. This is the fundamental reason for feature selection in Lasso!

---

*Notes compiled on 2026-10-07*
