# Scientific Article Management

## ORM Stimulation (Object-Relational Mapping)

- Entities (Author, Article, Journal) describe the data.
- Repositories support to create, search, store, ...

## Fxtui

Main()
↓
Khởi tạo ScreenInteractive
↓
Tạo Component Tree
↓
Render() → Element Tree (virtual)
↓
Layout + Diff + Draw → Hiển thị ra Terminal
↓
Vòng lặp:
├─ Nhận Event (keyboard, resize,…)
├─ Gửi Event xuống component
├─ Component xử lý & Post yêu cầu redraw
└─ Render lại khi cần
↓
Thoát và khôi phục terminal
