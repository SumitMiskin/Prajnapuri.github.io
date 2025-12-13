<!-- Copilot / AI agent instructions for Prajnapuri.github.io -->
# Copilot instructions — Prajnapuri.github.io

Purpose: quickly orient an AI coding assistant to be productive in this repository.

Big picture
- This is a small, static GitHub Pages site composed of standalone HTML pages in the repo root (e.g., `index.html`, `shrinivas.html`, `sumit.html`).
- Styling and layout are centralized in `css/styles.css` and behaviour in `js/scripts.js`.
- Image and binary assets live under `assets/` (e.g., `assets/img/portfolio/`, `assets/favicon.ico`).
- Pages use Bootstrap (via CDN) and FontAwesome (via CDN). There is no build tool, templating engine, or backend — pages are rendered as static files.

Key files to reference
- `index.html` — the main page; contains site-wide navigation, portfolio modals, and examples of common patterns (masthead, portfolio grid).
- `css/styles.css` — site styling; look here for class names like `.info-box`, `.idea-box`, `.intro-card`.
- `js/scripts.js` — interactive behaviour (modal triggers, small UI glue).
- `assets/img/portfolio/*` and `assets/img/avataaars.svg` — images referenced inline from pages.
- `README.md` — minimal repo description.

Patterns and conventions (concrete)
- Pages are standalone HTML files. When adding a new page you must update the navigation in every page (see the `<nav id="mainNav">` block in `index.html` and `shrinivas.html`).
- Filenames use lowercase and hyphens (e.g., `city-survey.html`, `resource-distribution.html`). Follow this naming when adding files.
- Navigation uses `id="mainNav"` and the `nav-link` classes across pages — keep these consistent to preserve styling/behavior.
- Background images for mastheads are applied inline via `style="background-image: url('assets/...')"` in the header element. Use the same pattern for hero images.
- Portfolio modals are defined inline in `index.html`. If adding a new portfolio item, add the modal markup there and a matching trigger image block.

Developer workflows (how to run / preview)
- No build step. To preview locally:
  - Open `index.html` in a browser (double-click) OR
  - From PowerShell run: `python -m http.server 8000` then visit `http://localhost:8000` (serves all files with correct relative paths).
  - Alternatively, use VS Code Live Server extension to preview changes with automatic reload.
- Deployment: repository name `Prajnapuri.github.io` implies GitHub Pages will publish the `main` branch automatically. Push to `main` to publish updates.

Integration points / external dependencies
- Bootstrap and Font Awesome loaded from CDN in `index.html` and other pages. Network access is required when previewing without bundling.
- `https://cdn.startbootstrap.com/sb-forms-latest.js` appears in `index.html` but contact forms are not configured — safe to ignore unless adding forms.

When making changes (practical checklist)
- Update navigation links in every top-level HTML file after adding/removing pages.
- Add new CSS rules to `css/styles.css` rather than scattering inline styles (exceptions: inline background-image on masthead is deliberate).
- Put images under `assets/img/...` and reference them with relative paths (e.g., `assets/img/portfolio/my-image.jpg`).
- Keep JavaScript hooks (data attributes like `data-bs-toggle`) consistent with Bootstrap 5 usage already present.

Examples (copy-paste friendly)
- Add a nav item (insert into every page's `<ul class="navbar-nav ms-auto">`):
  `<li class="nav-item mx-0 mx-lg-1"><a class="nav-link py-3 px-0 px-lg-3 rounded" href="newpage.html">New Page</a></li>`
- Quick local preview (PowerShell):
  `python -m http.server 8000`

Notes for an AI assistant
- Do not assume a templating system — edits must touch every page where repeated markup (nav, footer) appears.
- Prefer minimal, targeted changes. This project is intended as a teaching/demo static site — avoid large refactors unless asked.
- Keep file naming and existing CSS class names consistent; follow the concrete examples above.

If something is unclear or you need deeper context (e.g., add a new interactive feature or restructure layout), ask for the desired page(s) and I will update the relevant HTML/CSS/JS with concrete diffs.

-- End of instructions
