# PlantUML Class Diagrams - Scientific Article Management

Thư mục này chứa các sơ đồ lớp PlantUML cho hệ thống quản lý bài báo khoa học.

## Cấu trúc các file

### 1. Base Classes

- **01_article_base.puml** - Lớp cơ sở trừu tượng Article
  - Chứa các thuộc tính và phương thức chung
  - Hỗ trợ polymorphism và JSON serialization

### 2. Enumerations

- **02_article_enums.puml** - Các enum types
  - `ArticleStatus`: Trạng thái bài báo (DRAFT, SUBMITTED, PUBLISHED, v.v.)
  - `Type`: Loại bài báo (SCIE, SCOPUS, CONFERENCE, v.v.)

### 3. Specialized Article Classes

- **03_scie_article.puml** - Lớp SCIE_Article

  - Impact Factor
  - Q-rank (Q1-Q4)

- **04_scopus_article.puml** - Lớp SCOPUS_Article

  - SJR ranking
  - H-index

- **05_conference_article.puml** - Lớp CONFERENCE_Article

  - Conference rank
  - Location
  - Acceptance rate

- **06_other_article.puml** - Lớp OTHER_Article

  - Loại bài báo chung
  - Không thuộc các danh mục đặc biệt

- **07_custom_article.puml** - Lớp CUSTOM_Article
  - Custom type name
  - Flexible article type

### 4. Complete Diagram

- **08_article_hierarchy_complete.puml** - Sơ đồ đầy đủ
  - Tất cả các lớp và mối quan hệ
  - Overview toàn bộ hệ thống

## Cách sử dụng

### Xem sơ đồ trong VS Code

1. Cài đặt extension: **PlantUML** (jebbs.plantuml)
2. Mở file `.puml` bất kỳ
3. Nhấn `Alt+D` để xem preview

### Xuất ra file ảnh

```bash
# Cần cài đặt PlantUML và Graphviz
java -jar plantuml.jar *.puml
```

### Online

Truy cập [PlantUML Online Editor](http://www.plantuml.com/plantuml/uml/) và paste nội dung file.

## Mối quan hệ giữa các lớp

```
Article (Abstract)
├── SCIE_Article
├── SCOPUS_Article
├── CONFERENCE_Article
├── OTHER_Article
└── CUSTOM_Article
```

Tất cả các lớp con đều:

- Kế thừa từ `Article`
- Implement `clone()` cho deep copy
- Implement `to_json()` cho serialization
- Có thuộc tính riêng theo loại bài báo

## Ghi chú

- Các thuộc tính `#` là protected (được kế thừa)
- Các thuộc tính `-` là private
- Các phương thức `+` là public
- `unique_ptr<Article>` được dùng cho polymorphic ownership
